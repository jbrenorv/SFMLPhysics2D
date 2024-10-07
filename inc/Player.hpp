#pragma once

#include <SFML/Graphics.hpp>
#include "RigidBody2D.hpp"

class Player : public sf::Drawable, public RigidBody2D
{
public:

    Player(float mass, sf::Vector2f position);

    ~Player();

    void update(const sf::Time& time) override;

    const sf::FloatRect getBounds() const;

    void ground();

    void jump();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

    sf::Sprite m_sprite;
};
