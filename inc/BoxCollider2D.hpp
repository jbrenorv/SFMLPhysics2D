#pragma once

#include <SFML/Graphics.hpp>
#include "CollisionDetector.hpp"

enum class CollisionSide { Left, Right, Top, Bottom };

class BoxCollider2D
{
protected:

    BoxCollider2D();

private:

    friend class CollisionDetector;

    virtual const sf::FloatRect getBounds() const = 0;

    // Event funcion called by CollisionDetector
    virtual void onColliding(const CollisionSide& collisionSide) = 0;
};
