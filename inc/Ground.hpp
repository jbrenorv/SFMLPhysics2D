#pragma once

#include <SFML/Graphics.hpp>
#include "BoxCollider2D.hpp"

class Ground : public sf::Drawable, public BoxCollider2D
{
public:

    Ground(const sf::Vector2f& size);

    ~Ground();

    void setSize(const sf::Vector2f size);
    void setOrigin(const sf::Vector2f origin);
    void setTexture(const sf::Texture *texture);
    void setPosition(const sf::Vector2f position);

    const sf::Vector2f& getSize() const;
    const sf::Vector2f& getOrigin() const;
    const sf::Texture *getTexture() const;
    const sf::Vector2f& getPosition() const;

private:

    virtual const BoxInfo getBoxInfo() const;

    virtual void onColliding(const int collisionSide);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::RectangleShape m_shape;
};
