#pragma once
#include "List.h"
#include "GamePhysics/ColliderComponent.h"

namespace GameCore
{
	class Component;
	class Scene;

	class Entity
	{
	public:
		Entity();

		~Entity();

		/// <summary>
		/// adds the entity
		/// </summary>
		void added();
		/// <summary>
		/// Removes the entity
		/// </summary>
		void removed();
		//Called before the first update function
		void start();
		//caleed after the first start call
		void update(float deltaTime);
		//handles all the physics updates
		void fixedUpdate(float fixedFrameRate);
		void draw();
		void close();
		// The collision of the entities
		void collision(Entity* other);

		//Called during when entity is added
		virtual void onAdded() {}
		//Called when entity is removed
		virtual void onRemoved() {}
		//Called during start
		virtual void onStart() {}
		//Called during update
		virtual void onUpdate(float deltaTime) {}
		//Called during Fixed update
		virtual void onFixedUpdate(float fixedDeltaTime) {}
		virtual void onDraw() {}
		virtual void onEnd() {}
		//Called when it gets the collision of the entities
		virtual void onCollision(Entity* other) {}

		template<typename T>
		T* getComponent();

		
		void add(Component* component);
		void remove(Component* component);

		Scene* getScene() { return m_scene; }

	private:
		void setScene(Scene* scene) { m_scene = scene; }


	private:
		bool m_hasStarted = false;
		Scene* m_scene = nullptr;
		List<Component*> m_components;

		
		friend Scene;
	};
	
	//gets the components of the entities
	template<typename T>
	inline T* Entity::getComponent()
	{
		//Iterate through the component array
		for (Component* component : m_components)
		{
			T* temp = dynamic_cast<T*>(component);
			//Return the component if the name is the same as the current component
			if (temp)
				return (T*)component;
		}
		//Return nullptr if the component is not in the list
		return nullptr;
	}
}


