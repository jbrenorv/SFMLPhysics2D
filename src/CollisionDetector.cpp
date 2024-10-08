#include "CollisionDetector.hpp"

void CollisionDetector::addBox(const BoxCollider2D &box)
{
    m_boxes.push_back(box);
}

CollisionSide CollisionDetector::getCollisionSide(const sf::FloatRect &a, const sf::FloatRect &b)
{
    
    return CollisionSide();
}

void CollisionDetector::checkForCollisions(const BoxCollider2D &box)
{
    for (int i = 0; i < m_boxes.size(); i++)
    {
        sf::FloatRect a = m_boxes[i].getBounds();
        for (int j = (i + 1); j < m_boxes.size(); j++)
        {
            sf::FloatRect b = m_boxes[j].getBounds();

            if (a.intersects(b))
            {
                m_boxes[i].onColliding(getCollisionSide(a, b));
                m_boxes[j].onColliding(getCollisionSide(b, a));
            }
        }
    }
}
