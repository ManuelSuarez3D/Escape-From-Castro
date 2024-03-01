#include "Physics.h"
#include <cmath>

//sf::Vector2f Physics::getOverlapEntity(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b)
//{
//    sf::Vector2f overlap(0.f, 0.f);
//    if (!a->hasComponent<CBoundingBox>() or !b->hasComponent<CBoundingBox>())
//        return overlap;
//
//    auto atx = a->getComponent<CTransform>();
//    auto abb = a->getComponent<CBoundingBox>();
//    auto btx = b->getComponent<CTransform>();
//    auto bbb = b->getComponent<CBoundingBox>();
//
//
//    if (abb.has && bbb.has)
//    {
//        float dx = std::abs(atx.pos.x - btx.pos.x);
//        float dy = std::abs(atx.pos.y - btx.pos.y);
//        overlap = sf::Vector2f(abb.halfSize.x + bbb.halfSize.x - dx, abb.halfSize.y + bbb.halfSize.y - dy);
//    }
//    return overlap;
//}

sf::Vector2f Physics::getOverlapEntity(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b, std::string entityName)
{
    sf::Vector2f overlap(0.f, 0.f);
    if (!a->hasComponent<CBoundingBox>() || !b->hasComponent<CBoundingBox>())
        return overlap;

    auto atx = a->getComponent<CTransform>();
    auto abb = a->getComponent<CBoundingBox>();
    auto btx = b->getComponent<CTransform>();
    auto bbb = b->getComponent<CBoundingBox>();

    if (abb.has && bbb.has)
    {
        if (entityName == "shark") {
            // Calculate the bottom sections of a and b
            float bottomA = atx.pos.y + abb.halfSize.y - 5.f;
            float bottomB = btx.pos.y + bbb.halfSize.y - 5.f;
            // Calculate the left and right edges of the bottom section of b
            float leftB = btx.pos.x - bbb.halfSize.x;
            float rightB = btx.pos.x + bbb.halfSize.x;

            // Calculate the left and right edges of the bottom section of a, 5 units in height from the bottom
            float leftA = atx.pos.x - abb.halfSize.x + 45.f;
            float rightA = atx.pos.x + abb.halfSize.x;

            // Check if the bottom section of a overlaps with the bottom section of b
            if (bottomA >= bottomB && leftA <= rightB && rightA >= leftB)
            {
                // Calculate the overlap
                float dx = std::abs(atx.pos.x - btx.pos.x);
                float dy = std::abs(bottomA - bottomB);
                overlap = sf::Vector2f(abb.halfSize.x + bbb.halfSize.x - dx, 5.f + 5.f - dy); // Both boxes are 5.f in height
            }
        }
        else if (entityName == "coral") {

            float bottomA = atx.pos.y + abb.halfSize.y - 5.f;
            float bottomB = btx.pos.y + bbb.halfSize.y - 5.f;

            float leftB = btx.pos.x - bbb.halfSize.x + 8.f;
            float rightB = btx.pos.x + bbb.halfSize.x - 10.f;

            float leftA = atx.pos.x - abb.halfSize.x + 45.f;
            float rightA = atx.pos.x + abb.halfSize.x;

            if (bottomA >= bottomB && leftA <= rightB && rightA >= leftB)
            {
                float dx = std::abs(atx.pos.x - btx.pos.x);
                float dy = std::abs(bottomA - bottomB);
                overlap = sf::Vector2f(abb.halfSize.x + bbb.halfSize.x - dx, 5.f + 5.f - dy);
            }
        }
        else if (entityName == "boatMilitary") {
            // Calculate the bottom sections of a and b
            float bottomA = atx.pos.y + abb.halfSize.y - 5.f;
            float bottomB = btx.pos.y + bbb.halfSize.y - 10.f;
            // Calculate the left and right edges of the bottom section of b
            float leftB = btx.pos.x - bbb.halfSize.x + 30.f;
            float rightB = btx.pos.x + bbb.halfSize.x - 61.f;

            // Calculate the left and right edges of the bottom section of a, 5 units in height from the bottom
            float leftA = atx.pos.x - abb.halfSize.x + 45.f;
            float rightA = atx.pos.x + abb.halfSize.x;

            // Check if the bottom section of a overlaps with the bottom section of b
            if (bottomA >= bottomB && leftA <= rightB && rightA >= leftB)
            {
                // Calculate the overlap
                float dx = std::abs(atx.pos.x - btx.pos.x);
                float dy = std::abs(bottomA - bottomB);
                overlap = sf::Vector2f(abb.halfSize.x + bbb.halfSize.x - dx, 5.f + 10.f - dy); // Both boxes are 5.f in height
            }
        }
        else if (entityName == "island") {
            // Calculate the bottom sections of a and b
            float bottomA = atx.pos.y + abb.halfSize.y - 5.f;
            float bottomB = btx.pos.y + bbb.halfSize.y - 15.f;
            // Calculate the left and right edges of the bottom section of b
            float leftB = btx.pos.x - bbb.halfSize.x + 10.f; // The hit box is 10 from the left side
            float rightB = btx.pos.x + bbb.halfSize.x - 19.f; // The hit box is 19 on the right

            // Calculate the left and right edges of the bottom section of a, 5 units in height from the bottom
            float leftA = atx.pos.x - abb.halfSize.x + 45.f;
            float rightA = atx.pos.x + abb.halfSize.x;

            // Check if the bottom section of a overlaps with the bottom section of b
            if (bottomA >= bottomB && leftA <= rightB && rightA >= leftB)
            {
                // Calculate the overlap
                float dx = std::abs(atx.pos.x - btx.pos.x);
                float dy = std::abs(bottomA - bottomB);
                overlap = sf::Vector2f(abb.halfSize.x + bbb.halfSize.x - dx, 5.f + 15.f - dy);
            }
        }
        //// Calculate the bottom sections of a and b
        //float bottomA = atx.pos.y + abb.halfSize.y;
        //float bottomB = btx.pos.y + bbb.halfSize.y;
        //// Calculate the left and right edges of the bottom section of b
        //float leftB = btx.pos.x - bbb.halfSize.x;
        //float rightB = btx.pos.x + bbb.halfSize.x;

        //// Calculate the left and right edges of the bottom section of a, 5 units in height from the bottom
        //float leftA = atx.pos.x - abb.halfSize.x + 45.f;
        //float rightA = atx.pos.x + abb.halfSize.x;

        //// Check if the bottom section of a overlaps with the bottom section of b
        //if (bottomA >= bottomB && leftA <= rightB && rightA >= leftB)
        //{
        //    // Calculate the overlap
        //    float dx = std::abs(atx.pos.x - btx.pos.x);
        //    float dy = std::abs(bottomA - bottomB);
        //    overlap = sf::Vector2f(abb.halfSize.x + bbb.halfSize.x - dx, 5.f - dy); // Both boxes are 5.f in height
        //}
    }
    return overlap;
}
sf::Vector2f Physics::getOverlapMouse(sf::Vector2f a, std::shared_ptr<Entity> b)
{
    sf::Vector2f overlap(0.f, 0.f);

    auto btx = b->getComponent<CTransform>();
    auto bbb = b->getComponent<CBoundingBox>();

    if (btx.has && bbb.has)
    {
        float dx = std::abs(a.x - btx.pos.x);
        float dy = std::abs(a.y - btx.pos.y);

        float overlapX = bbb.halfSize.x - dx;
        float overlapY = bbb.halfSize.y - dy;

        overlapX = std::max(overlapX, 0.f);
        overlapY = std::max(overlapY, 0.f);

        overlap = sf::Vector2f(overlapX, overlapY);
    }

    return overlap;
}

sf::Vector2f Physics::getPreviousOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b)
{
    sf::Vector2f overlap(0.f, 0.f);
    if (!a->hasComponent<CBoundingBox>() or !b->hasComponent<CBoundingBox>())
        return overlap;

    auto atx = a->getComponent<CTransform>();
    auto abb = a->getComponent<CBoundingBox>();
    auto btx = b->getComponent<CTransform>();
    auto bbb = b->getComponent<CBoundingBox>();

    if (abb.has && bbb.has)
    {
        float dx = std::abs(atx.prevPos.x - btx.prevPos.x);
        float dy = std::abs(atx.prevPos.y - btx.prevPos.y);
        overlap = sf::Vector2f(abb.halfSize.x + bbb.halfSize.x - dx, abb.halfSize.y + bbb.halfSize.y - dy);
    }
    return overlap;
}
