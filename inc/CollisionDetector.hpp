#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "BoxCollider2D.hpp"

class CollisionDetector
{
public:

    static void checkForCollisions(const BoxCollider2D& box);

protected:

    friend class BoxCollider2D;

    static void addBox(const BoxCollider2D& box);

private:

    static CollisionSide getCollisionSide(const sf::FloatRect& a, const sf::FloatRect& b);

    static std::vector<BoxCollider2D> m_boxes;
};
