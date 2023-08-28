#include "pch.h"
#include "RigidBodyComponent.h"

GamePhysics::RigidBodyComponent::RigidBodyComponent(float mass = 1.0f, float elasticity = 1.0f)
{
	m_mass = mass;
}

void GamePhysics::RigidBodyComponent::onFixedUpdate(float fixedDeltaTIme)
{
	//Calculate current position
	//p1 = p0 + vt
	setLocalPosition(getLocalPosition() + m_velocity * fixedDeltaTIme);

	//Appply Gravity
	applyForce(m_gravity * m_mass, fixedDeltaTIme);
}

void GamePhysics::RigidBodyComponent::applyForce(GameMath::Vector3 force, float Time)
{

	//a = f/m
	m_acceleration = force / m_mass;
	//v1 = v0 + at
	m_velocity = m_velocity + m_acceleration * Time;
}

GameMath::Vector3 GamePhysics::RigidBodyComponent::getCollisionNomral(RigidBodyComponent* other)
{
	return (getGlobalPosition() - other->getGlobalPosition()).getNormalized();
}

float GamePhysics::RigidBodyComponent::getImpulse(RigidBodyComponent* other, GameMath::Vector3 collisionNormal)
{
	GameMath::Vector3 velocity = getVelocity() - other->getVelocity();

	float velocityDotProduct = GameMath::Vector3().dotProduct(velocity, collisionNormal);

	float collisionNormalDotProduct = GameMath::Vector3().dotProduct(collisionNormal, collisionNormal);

	float impulse = (-(1.0f + m_elasticity) * velocityDotProduct) /
		(collisionNormalDotProduct * (1.0f / getMass() + 1.0f / other->getMass()));

	return impulse;
	
	
	/*float dotVelocityCollisionNormal = GameMath::Vector3().dotProduct(getVelocity() - other->getVelocity(), collisionNormal);
	float dotCollisionNormal = GameMath::Vector3().dotProduct(collisionNormal, collisionNormal);

	return (-(1 + m_elasticity) * dotCollisionNormal) / (dotCollisionNormal * (1 / getMass() + 1 / other->getMass()));*/
}

void GamePhysics::RigidBodyComponent::resloveCollision(RigidBodyComponent other)
{
	GameMath::Vector3 velocityA = getVelocity();
	float massA = getMass();
	GameMath::Vector3 velocityB = other.getVelocity();
	float massB = other.getMass();
	float elasticity = getElasticity();
}




