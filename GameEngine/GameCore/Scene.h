#pragma once
#include "List.h"
#include "GamePhysics/ColliderComponent.h"

namespace GamePhysics
{
	class ColliderComponent;
}

namespace GameCore 
{
	class Entity;

	class Scene
	{
	public:
		Scene();

		/// <summary>
		/// Called before the first update for this scene. It is not necessary to call this function.
		/// </summary>
		void start();
		/// <summary>
		/// Called after after the start function
		/// </summary>
		/// <param name="updates the function using delta time"></param>
		void update(float deltaTime);
		/// <summary>
		/// Handle all the physics update seperate from the update function
		/// </summary>
		/// <param name="updates using fixed frame rate "></param>
		void fixedUpdate(float fixedFrameRate);
		void draw();
		void close();

		/// <summary>
		/// Called before the first update for this scene. Overrride this function.
		/// </summary>
		virtual void onStart() {}
		/// <summary>
		/// Called every Frame after on start for this scene or each update loop. Override this function.
		/// </summary>
		/// <param name="deltaTime"></param>
		virtual void onUpdate(float deltaTime) {}
		/// <summary>
		/// Called every frame after on start for this scene or each fixed update handling physics. Override this function
		/// </summary>
		/// <param name="fixedDeltaTime"></param>
		virtual void onFixedUpdate(float fixedDeltaTime) {}
		/// <summary>
		/// Called each loop after update. Override this function.
		/// </summary>
		virtual void onDraw() {}
		virtual void onEnd() {}

		/// <summary>
		/// Add an Entity to the scene.
		/// </summary>
		/// <param name="entity"></param>
		void add(Entity* entity);
		/// <summary>
		/// Remove and Entity from the scene.
		/// </summary>
		/// <param name="entity"></param>
		void remove(Entity* entity);

		/// <summary>
		/// Adds the collider to the scene
		/// </summary>
		/// <param name="collider"></param>
		void addCollider(GamePhysics::ColliderComponent* collider);
		/// <summary>
		/// Remove the collider from the scene
		/// </summary>
		/// <param name="colldier"></param>
		void removeCollider(GamePhysics::ColliderComponent* colldier);

	private:
		bool m_hasStarted = false;
		List<Entity*> m_entities;
		List<GamePhysics::ColliderComponent*> m_collider;
	};
}


