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

    Ground platform(sf::Vector2f(960, 10));
    platform.setPosition(sf::Vector2f(0, 200));

    Player player(45, sf::Vector2f(0, 250));

    CollisionDetector *collisionDetector = CollisionDetector::getInstance();
    collisionDetector->addBox(&player);
    collisionDetector->addBox(&ground);
    collisionDetector->addBox(&platform);

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

        collisionDetector->checkForCollisions();
        player.update(clock.restart());

        window.clear();
        window.draw(player);
        window.draw(ground);
        window.draw(platform);
        window.display();
    }

    return EXIT_SUCCESS;
}
