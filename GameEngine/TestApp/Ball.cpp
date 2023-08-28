#include "Ball.h"
#include "GameGraphics/CircleComponent.h"
#include "GamePhysics/RigidBodyComponent.h"
#include "GamePhysics/SphereColliderComponent.h"


Ball::Ball(float radius, float mass, float elasticity, GameMath::Vector4 color)
{
	////Set up rigid body
	//m_rigidBody = new GamePhysics::RigidBodyComponent(mass, elasticity);
	//add(m_rigidBody);
	//set up circle 
	m_circle = new GameGraphics::CircleComponent(radius, color);
	m_circle->setParent(getRigidBodyComponent());
	add(m_circle);

	//set up sphere collider
	m_collider = new GamePhysics::SphereColliderComponent(radius);
	m_collider->setParent(getRigidBodyComponent());
	add(m_collider);
}

Ball::~Ball()
{
	/*delete m_rigidBody;*/
	delete m_collider;
	delete m_circle;
}



//void Ball::onCollision()
//{
//	m_circle->setColor({ 1.0f,8.0f,5.0f,1.0f });
//}
