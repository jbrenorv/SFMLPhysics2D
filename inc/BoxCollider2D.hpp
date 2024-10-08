#pragma once

#include <SFML/Graphics.hpp>
#include "CollisionDetector.hpp"

struct BoxInfo;

class BoxCollider2D
{
public:

    virtual const BoxInfo getBoxInfo() const = 0;

    // Event funcion called by CollisionDetector
    virtual void onColliding(const int collisionSide) = 0;
};
