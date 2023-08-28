#pragma once
#include "GameCore/Entity.h"


namespace GamePhysics
{
	class RigidBodyComponent;

	class PhysicsEntity :
		public GameCore::Entity
	{
	public:
		PhysicsEntity(float mass = 1.0f, float elasticty = 1.0f);
		~PhysicsEntity();

		GamePhysics::RigidBodyComponent* getRigidBodyComponent() { return m_rigidBody; }

		//Gets the collision of the entity for the physics entity
		void onCollision(Entity* other);



	private:
		GamePhysics::RigidBodyComponent* m_rigidBody;

	};
}


