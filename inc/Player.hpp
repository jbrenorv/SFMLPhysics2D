#pragma once

#include <SFML/Graphics.hpp>
#include "RigidBody2D.hpp"
#include "BoxCollider2D.hpp"

class Player : public sf::Drawable, public RigidBody2D, public BoxCollider2D
{
public:

    Player(float mass, sf::Vector2f position);

    ~Player();

    void update(const sf::Time& time) override;

    void jump();
    void moveX(bool left, bool right);

private:

    virtual const BoxInfo getBoxInfo() const;

    virtual void onColliding(const int collisionSide);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    bool m_jumpping;
    sf::Sprite m_sprite;
};
