#pragma once

#include <SFML/Graphics.hpp>

class RigidBody2D
{
public:

    RigidBody2D(float mass, sf::Vector2f position);

    ~RigidBody2D();

    virtual void update(const sf::Time& time);

protected:

    const sf::Vector2f k_gravity = sf::Vector2f(0.f, 900.0f);

    sf::Vector2f m_currentGravity;
    sf::Vector2f m_speed;
    sf::Vector2f m_position;
};
