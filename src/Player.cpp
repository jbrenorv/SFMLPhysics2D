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

void Player::ground()
{
    m_fy.x = -m_fy.y;
    m_speed = sf::Vector2f(0, 0);
}

void Player::jump()
{
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_sprite);
}
