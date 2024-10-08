#include "CollisionDetector.hpp"

CollisionDetector* CollisionDetector::__instance = nullptr;

CollisionDetector *CollisionDetector::getInstance()
{
    if (__instance == nullptr)
    {
        __instance = new CollisionDetector();
    }
    return __instance;
}

CollisionDetector::CollisionDetector()
{
    m_oppositeSide = std::map<int, int>{
        {CollisionDetector::LEFT,  CollisionDetector::RIGHT },
        {CollisionDetector::RIGHT, CollisionDetector::LEFT  },
        {CollisionDetector::BOTTOM,CollisionDetector::TOP   },
        {CollisionDetector::TOP,   CollisionDetector::BOTTOM},
        {CollisionDetector::NONE,  CollisionDetector::NONE  }};
}

void CollisionDetector::addBox(BoxCollider2D *box)
{
    m_boxes.push_back(box);
}

int CollisionDetector::getCollisionSide(const BoxInfo& a, const BoxInfo& b)
{
    if (a.speed == sf::Vector2f(0, 0) && a.speed != b.speed)
    {
        int collisionSideBA = getCollisionSide(b, a);
        return m_oppositeSide[collisionSideBA];
    }

    float aMinX = a.bounds.left;
    float aMaxX = a.bounds.left + a.bounds.width;
    float aMinY = a.bounds.top;
    float aMaxY = a.bounds.top + a.bounds.height;
    float bMinX = b.bounds.left;
    float bMaxX = b.bounds.left + b.bounds.width;
    float bMinY = b.bounds.top;
    float bMaxY = b.bounds.top + b.bounds.height;

    float commonX = std::min(aMaxX, bMaxX) - std::max(aMinX, bMinX);
    float commonY = std::min(aMaxY, bMaxY) - std::max(aMinY, bMinY);

    int result;

    if (a.speed.y == 0)
    {
        if (a.speed.x > 0)
        {
            // left to right
            result = CollisionDetector::RIGHT;
        }
        else
        {
            // right to left
            result = CollisionDetector::LEFT;
        }
    }
    if (a.speed.y > 0)
    {
        if (a.speed.x == 0 || commonX > commonY)
        {
            // from top to bottom
            result = CollisionDetector::BOTTOM;
        }
        else if (a.speed.x > 0)
        {
            // from top to bottom and left to right
            result = CollisionDetector::RIGHT;
        }
        else
        {
            // from top to bottom and right to left
            result = CollisionDetector::LEFT;
        }
    }
    else
    {
        if (a.speed.x == 0 || commonX > commonY)
        {
            // from bottom to top
            result = CollisionDetector::TOP;
        }
        else if (a.speed.x > 0)
        {
            // from bottom to top and left to right
            result = CollisionDetector::RIGHT;
        }
        else
        {
            // from bottom to top and right to left
            result = CollisionDetector::LEFT;
        }
    }

    if ((result == CollisionDetector::LEFT   && aMinX < bMinX) ||
        (result == CollisionDetector::RIGHT  && aMaxX > bMaxX) ||
        (result == CollisionDetector::TOP    && aMinY < bMinY) ||
        (result == CollisionDetector::BOTTOM && aMaxY > bMaxY))
    {
        result = CollisionDetector::NONE;
    }

    return result;
}

void CollisionDetector::checkForCollisions()
{
    int n = m_boxes.size();
    
    std::vector<bool> colliding(n, false);

    for (int i = 0; i < n; i++)
    {
        BoxInfo a = m_boxes[i]->getBoxInfo();
        for (int j = (i + 1); j < n; j++)
        {
            BoxInfo b = m_boxes[j]->getBoxInfo();

            if (a.bounds.intersects(b.bounds))
            {
                int collisionSideAB = getCollisionSide(a, b);
                m_boxes[i]->onColliding(collisionSideAB);
                m_boxes[j]->onColliding(m_oppositeSide[collisionSideAB]);

                colliding[i] = colliding[j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!colliding[i])
        {
            m_boxes[i]->onColliding(CollisionDetector::NONE);
        }
    }
}
