#include "Ground.hpp"

Ground::Ground(const sf::Vector2f& size)
{
    m_shape = sf::RectangleShape(size);
}

Ground::~Ground()
{
}

void Ground::setSize(const sf::Vector2f size)
{
    m_shape.setSize(size);
}

void Ground::setOrigin(const sf::Vector2f origin)
{
    m_shape.setOrigin(origin);
}

void Ground::setTexture(const sf::Texture *texture)
{
    m_shape.setTexture(texture);
}

void Ground::setPosition(const sf::Vector2f position)
{
    m_shape.setPosition(position);
}

const sf::Vector2f &Ground::getSize() const
{
    return m_shape.getSize();
}

const sf::Vector2f &Ground::getOrigin() const
{
    return m_shape.getOrigin();
}

const sf::Texture *Ground::getTexture() const
{
    return m_shape.getTexture();
}

const sf::Vector2f &Ground::getPosition() const
{
    return m_shape.getPosition();
}

const BoxInfo Ground::getBoxInfo() const
{
    return BoxInfo(sf::Vector2f(0, 0), m_shape.getGlobalBounds());
}

void Ground::onColliding(const int collisionSide)
{
}

void Ground::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_shape);
}
