#pragma once
#include "Vector4.h"
#include "GameCore/Entity.h"
#include "GamePhysics/PhysicsEntity.h"


namespace GameGraphics 
{
	class CircleComponent;
}
namespace GamePhysics
{
	class RigidBodyComponent;
	class SphereColliderComponent;
}
class Ball : public GamePhysics::PhysicsEntity
{
public:
	//stats for the ball
	Ball(float radius = 2.0f, float mass = 1.0f, float elasticity = 1.0f, GameMath::Vector4 color = GameMath::Vector4(1.0f,1.0f,1.0f, 1.0f));
	~Ball();

	

	//void onCollision() override;

	/*GamePhysics::RigidBodyComponent* getRigidBodyComponent() { return m_rigidBody; }*/
	GameGraphics::CircleComponent* getCircleComponent() { return m_circle; }
	GamePhysics::SphereColliderComponent* getCollider() { return m_collider; }

private:
	/*amePhysics::RigidBodyComponent* m_rigidBody;*/
	GameGraphics::CircleComponent* m_circle;
	GamePhysics::SphereColliderComponent* m_collider;



};

