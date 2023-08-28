#include "pch.h"
#include "SphereColliderComponent.h"
#include "Vector3.h"

GamePhysics::SphereColliderComponent::SphereColliderComponent(float radius)
{
    m_radius = radius;
}

bool GamePhysics::SphereColliderComponent::checkCollision(SphereColliderComponent* other)
{
    //Get the positions
    GameMath::Vector3 p1 = getGlobalPosition();
    GameMath::Vector3 p2 = other->getGlobalPosition();
    //Calculate the distance
    // d = |sqrt((x1-x2)^2 + (y1-y2)^2 + (z1-z2)^2|
    float distance = fabsf(sqrtf(
        powf(p1.x - p2.x, 2.0f) +
        powf(p1.y - p2.y, 2.0f) +
        powf(p1.z - p2.z, 2.0f)));
    //Compare distance to combined radii
    return distance <= m_radius + other->m_radius;

}


bool GamePhysics::SphereColliderComponent::checkCollision(BoxColliderComponent* other)
{
    return false;
}

bool GamePhysics::SphereColliderComponent::checkCollision(PlaneColliderComponent* other)
{
    return false;
}

bool GamePhysics::SphereColliderComponent::checkCollision(ColliderComponent* other)
{
    return other->checkCollision(this);
}
