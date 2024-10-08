#include "BoxCollider2D.hpp"
#include "CollisionDetector.hpp"

BoxCollider2D::BoxCollider2D()
{
    CollisionDetector::addBox(*this);
}
