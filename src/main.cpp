#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Player.hpp"
#include "Ground.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(960, 540), "SFML Physics 2D");

    sf::Clock clock;

    Ground ground(sf::Vector2f(960, 50));
    ground.setOrigin(ground.getSize());
    ground.setPosition(sf::Vector2f(window.getSize()));

    Ground p0(sf::Vector2f(100, 10));
    Ground p1(sf::Vector2f(100, 10));
    Ground p2(sf::Vector2f(100, 10));
    p0.setPosition(sf::Vector2f(100, 280));
    p1.setPosition(sf::Vector2f(760, 280));
    p2.setPosition(sf::Vector2f(430, 220));

    Player player(45, sf::Vector2f(0, 250));

    CollisionDetector *collisionDetector = CollisionDetector::getInstance();
    collisionDetector->addBox(&player);
    collisionDetector->addBox(&ground);
    collisionDetector->addBox(&p0);
    collisionDetector->addBox(&p1);
    collisionDetector->addBox(&p2);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            player.jump();
        }

        bool moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        bool moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        player.moveX(moveLeft, moveRight);

        collisionDetector->checkForCollisions();

        player.update(clock.restart());

        window.clear();
        window.draw(player);
        window.draw(ground);
        window.draw(p0);
        window.draw(p1);
        window.draw(p2);
        window.display();
    }

    return EXIT_SUCCESS;
}
