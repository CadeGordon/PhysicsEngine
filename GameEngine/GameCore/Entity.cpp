#include "pch.h"
#include "Entity.h"
#include "List.h"
#include <iostream>
#include "Component.h"
#include "GamePhysics/ColliderComponent.h"
#include "Scene.h"

GameCore::Entity::Entity()
{
}

GameCore::Entity::~Entity()
{
}

void GameCore::Entity::added()
{
	//For each component in the components list...
	for (Component* component : m_components)
	{
		//if the component is a collider
		if (GamePhysics::ColliderComponent* collider = dynamic_cast<GamePhysics::ColliderComponent*>(component))
		{
			//add the component to the scenes collider list
			getScene()->addCollider(collider);
		}
			
	}
	onAdded();
}

void GameCore::Entity::removed()
{
	//For each component in the components list...
	for (Component* component : m_components)
	{
		//if the component is a collider
		if (GamePhysics::ColliderComponent* collider = dynamic_cast<GamePhysics::ColliderComponent*>(component))
		{
			getScene()->removeCollider(collider);
		}
		//add it component to the scenes collider list
	}

	onRemoved();
}

//called before the first update function
void GameCore::Entity::start()
{
	m_hasStarted = true;
	onStart();
}

//called after start
void GameCore::Entity::update(float deltaTime)
{
	if (!m_hasStarted)
	{
		start();
	}

	for (Component* component : m_components)
	{
		component->update(deltaTime);
	}

	onUpdate(deltaTime);

}

//handles all the physics updates
void GameCore::Entity::fixedUpdate(float fixedFrameRate)
{
	onFixedUpdate(fixedFrameRate);

	for (Component* component : m_components)
		component->fixedUpdate(fixedFrameRate);
}

void GameCore::Entity::draw()
{
	onDraw();

	for (Component* component : m_components)
	{
		component->draw();
	}
}

void GameCore::Entity::close()
{
	onEnd();
}

//Check the collision of the entity
void GameCore::Entity::collision(Entity* other)
{
	//Call on collision of the other entity
	onCollision(other);
}

void GameCore::Entity::add(Component* component)
{
	//If the component already has an owner
	//remove it from that owner
	if (Entity* oldOwner = component->getOwner())
	{
		oldOwner->remove(component);
	}
	//Add the component to this entity list
	m_components.add(component);
	//Set the component's owners to this entity
	component->setOwner(this);

}


void GameCore::Entity::remove(Component* component)
{
	//Remove the component from this entity from this entitys list
	m_components.remove(component);
	//Nullify the components owner
	component->setOwner(nullptr);
}
