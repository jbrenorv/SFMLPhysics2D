#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

#include "BoxCollider2D.hpp"

class BoxCollider2D;

struct BoxInfo
{
    BoxInfo(sf::Vector2f speed, sf::FloatRect bounds) : speed(speed), bounds(bounds)
    {
    }

    sf::Vector2f speed;
    sf::FloatRect bounds;
};

class CollisionDetector
{
public:

    static CollisionDetector *getInstance();

    void checkForCollisions();

    void addBox(BoxCollider2D* box);

    inline static const int LEFT    = 0;
    inline static const int RIGHT   = 1;
    inline static const int TOP     = 2;
    inline static const int BOTTOM  = 3;
    inline static const int NONE    = 4;

private:

    CollisionDetector();

    static CollisionDetector *__instance;

    int getCollisionSide(const BoxInfo& a, const BoxInfo& b);

    std::vector<BoxCollider2D*> m_boxes;
    std::map<int, int> m_oppositeSide;
};
