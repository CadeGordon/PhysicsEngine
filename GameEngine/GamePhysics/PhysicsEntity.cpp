#include "pch.h"
#include "PhysicsEntity.h"
#include "RigidBodyComponent.h"

GamePhysics::PhysicsEntity::PhysicsEntity(float mass, float elasticty)
{
	m_rigidBody = new GamePhysics::RigidBodyComponent(mass, elasticty);
	add(m_rigidBody);
}

GamePhysics::PhysicsEntity::~PhysicsEntity()
{
	delete (m_rigidBody);
}

//Handled the collision for the physics entity
void GamePhysics::PhysicsEntity::onCollision(Entity* other)
{
	RigidBodyComponent* otherRigidBody = other->getComponent<RigidBodyComponent>();

	if (!otherRigidBody)
		otherRigidBody = new RigidBodyComponent(false, std::numeric_limits<float>::infinity());

	GameMath::Vector3 position = getRigidBodyComponent()->getGlobalPosition();

	GameMath::Vector3 otherPosition = otherRigidBody->getGlobalPosition();

	GameMath::Vector3 collisionNormal = (position - otherPosition).getNormalized();
	
	float impluse = getRigidBodyComponent()->getImpulse(otherRigidBody, collisionNormal);

	getRigidBodyComponent()->applyForce(collisionNormal * impluse);
	otherRigidBody->applyForce(collisionNormal * -impluse);


}
