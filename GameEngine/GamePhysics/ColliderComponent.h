#pragma once
#include "GameCore/TransformComponent.h"

namespace GamePhysics
{
	class SphereColliderComponent;
	class BoxColliderComponent;
	class PlaneColliderComponent;

	class ColliderComponent :
		public GameCore::TransformComponent
	{
	public:
		ColliderComponent() {}

		//void onFixedUpdate(float fixedDeltaTime) override;

		//checks the collision of the sphere collider
		virtual bool checkCollision(SphereColliderComponent* other) { return false; }

		//collision set up for later date
		virtual bool checkCollision(BoxColliderComponent* other) { return false; }
		virtual bool checkCollision(PlaneColliderComponent* other) { return false; }
		virtual bool checkCollision(ColliderComponent* other) { return false; }

	private:
		bool m_isTrigger = false;
	};
}


