#include "Player.hpp"
#include "Assets.hpp"
#include "CollisionDetector.hpp"

Player::Player(float mass, sf::Vector2f position) : RigidBody2D(mass, position)
{
    m_sprite = Assets::getSprite(kPlayerImage);
    m_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    m_sprite.setPosition(position);
    m_sprite.scale(sf::Vector2f(2, 2));
}

Player::~Player()
{
}

void Player::update(const sf::Time& time)
{
    RigidBody2D::update(time);

    m_sprite.setPosition(m_position);
}

void Player::jump()
{
    m_currentGravity = k_gravity;
    m_speed = sf::Vector2f(0, -200);
}

const BoxInfo Player::getBoxInfo() const
{
    return BoxInfo(m_speed, m_sprite.getGlobalBounds());
}

void Player::onColliding(const int collisionSide)
{
    if (collisionSide == CollisionDetector::NONE)
    {
        m_currentGravity = k_gravity;
    }
    else if (collisionSide == CollisionDetector::BOTTOM)
    {
        if (m_speed.y >= 0.f)
        {
            m_currentGravity = sf::Vector2f(0, 0);
            m_speed = sf::Vector2f(0, 0);
        }
        else
        {
            m_currentGravity = k_gravity;
        }
    }
    else
    {
        m_speed = sf::Vector2f(0, 0);
    }
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_sprite);
}
