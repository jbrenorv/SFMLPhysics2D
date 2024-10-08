#include "Player.hpp"
#include "Assets.hpp"

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

const sf::FloatRect Player::getBounds() const
{
    return m_sprite.getGlobalBounds();
}

void Player::checkForGroundCollision(const sf::FloatRect& groundBounds)
{
    if (this->getBounds().intersects(groundBounds) && m_speed.y >= 0.f)
    {
        m_currentGravity = sf::Vector2f(0, 0);
        m_speed = sf::Vector2f(0, 0);
    }
    else
    {
        m_currentGravity = k_gravity;
    }
}

void Player::jump()
{
    m_currentGravity = k_gravity;
    m_speed = sf::Vector2f(0, -200);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_sprite);
}
