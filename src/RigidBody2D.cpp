#include <math.h>
#include "RigidBody2D.hpp"

RigidBody2D::RigidBody2D(float mass, sf::Vector2f position)
{
    m_mass = mass;
    m_position = position;
    m_speed = sf::Vector2f(0, 0);
    m_fx = sf::Vector2f(0, 0);
    m_fy = sf::Vector2f(0, mass * 9.8);
}

RigidBody2D::~RigidBody2D()
{
}

void RigidBody2D::update(const sf::Time& time)
{
    sf::Vector2f fr = sf::Vector2f(m_fx.x + m_fx.y, m_fy.x + m_fy.y);
    sf::Vector2f a = fr / m_mass;

    sf::Vector2f initialPosition = m_position;

    float s = time.asSeconds();

    m_position += m_speed * s + (a * s * s) / 2.0f;

    m_speed = (m_position - initialPosition) / s;
}
