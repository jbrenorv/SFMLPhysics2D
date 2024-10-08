#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <experimental/random>
#include <iostream>

#include "Player.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(960, 540), "SFML Physics 2D");

    sf::Clock clock;

    sf::RectangleShape ground(sf::Vector2f(960, 50));
    ground.setOrigin(ground.getSize());
    ground.setPosition(sf::Vector2f(window.getSize()));
    ground.setFillColor(sf::Color(0x949494FF));

    Player player(45, sf::Vector2f(0, 0));

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

        player.checkForGroundCollision(ground.getGlobalBounds());
        player.update(clock.restart());

        window.clear();
        window.draw(player);
        window.draw(ground);
        window.display();
    }

    return EXIT_SUCCESS;
}
