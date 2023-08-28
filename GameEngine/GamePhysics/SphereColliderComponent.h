#pragma once
#include "ColliderComponent.h"

namespace GamePhysics
{
	class BoxColliderComponent;
	class PlaneColliderComponent;


	class SphereColliderComponent :
		public GamePhysics::ColliderComponent
	{
	public:
		SphereColliderComponent(float radius = 1.0f);

		bool checkCollision(SphereColliderComponent* other) override;
		bool checkCollision(BoxColliderComponent* other) override;
		bool checkCollision(PlaneColliderComponent* other) override;
		bool checkCollision(ColliderComponent* other) override;

	private:
		float m_radius;
	};
}


