#pragma once

#include <SFML/Graphics.hpp>

class RigidBody2D
{
public:

    RigidBody2D(float mass, sf::Vector2f position);

    ~RigidBody2D();

    virtual void update(const sf::Time& time);

protected:

    float m_mass;

    sf::Vector2f m_fy;
    sf::Vector2f m_fx;
    sf::Vector2f m_speed;
    sf::Vector2f m_position;
};
