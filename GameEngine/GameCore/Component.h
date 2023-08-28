#pragma once

namespace GameCore
{
	class Entity;

	class Component
	{
	public:
		Component();

		/// <summary>
		/// Adds the Component
		/// </summary>
		void added();
		/// <summary>
		/// Removes the component
		/// </summary>
		void removed();
		/// <summary>
		/// Called before the first update function
		/// </summary>
		void start();
		/// <summary>
		/// Called after the start function
		/// </summary>
		/// <param name="deltaTime"></param>
		void update(float deltaTime);
		/// <summary>
		/// Handles all the physics updates
		/// </summary>
		/// <param name="fixedFrameRate"></param>
		void fixedUpdate(float fixedFrameRate);
		/// <summary>
		/// Draws to the window
		/// </summary>
		void draw();
		void end();

		/// <summary>
		/// Called during the added function this function is a overload
		/// </summary>
		virtual void onAdded() {}
		/// <summary>
		/// Called during the removed function This is a overload
		/// </summary>
		virtual void onRemoved() {}
		/// <summary>
		/// Called on start this is a overload
		/// </summary>
		virtual void onStart() {}
		/// <summary>
		/// Called during update this is a overload
		/// </summary>
		/// <param name="deltaTime"></param>
		virtual void onUpdate(float deltaTime) {}
		/// <summary>
		/// Called during fixed update this is a overload
		/// </summary>
		/// <param name="fixedDeltaTime"></param>
		virtual void onFixedUpdate(float fixedDeltaTime) {}
		virtual void onDraw() {}
		virtual void onEnd() {}

		/// <summary>
		/// gets the owner of the entity
		/// </summary>
		/// <returns> the owner </returns>
		Entity* getOwner() { return m_owner; }

	private:
		//sets the owner of the entity
		void setOwner(Entity* owner) { m_owner = owner; }

	private:
		bool m_hasStarted = false;
		Entity* m_owner = nullptr;

		friend Entity;
	};
}


