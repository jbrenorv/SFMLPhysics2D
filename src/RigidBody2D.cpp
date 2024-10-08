#include <math.h>
#include "RigidBody2D.hpp"

RigidBody2D::RigidBody2D(float mass, sf::Vector2f position)
{
    m_position = position;
    m_speed = sf::Vector2f(0, 0);
}

RigidBody2D::~RigidBody2D()
{
}

void RigidBody2D::update(const sf::Time& time)
{
    sf::Vector2f initialPosition = m_position;
    float s = time.asSeconds();

    m_position += m_speed * s + (m_currentGravity * s * s) / 2.0f;

    m_speed = (m_position - initialPosition) / s;
}
