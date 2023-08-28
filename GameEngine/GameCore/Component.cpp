#include "pch.h"
#include "Component.h"
#include "Entity.h"
#include "GamePhysics/ColliderComponent.h"
#include "Scene.h"

GameCore::Component::Component()
{
}

void GameCore::Component::added()
{
	//if owner is in a Scene
	if (Entity* owner = getOwner())
	{
		if (Scene* scene = owner->getScene())
		{
			//if the component is a collider
			if (GamePhysics::ColliderComponent* thisCollider = dynamic_cast<GamePhysics::ColliderComponent*>(this))
			{
				//add this component to the scenes collider list
				scene->addCollider(thisCollider);
			}
		}
		
	}
	onAdded();
}

void GameCore::Component::removed()
{
	//if owner is in a Scene
	if (Entity* owner = getOwner())
	{
		if (Scene* scene = owner->getScene())
		{
			//if the component is a collider
			if (GamePhysics::ColliderComponent* thisCollider = dynamic_cast<GamePhysics::ColliderComponent*>(this))
			{
				//add this component to the scenes collider list
				scene->removeCollider(thisCollider);
			}
		}

	}
	onRemoved();
}


void GameCore::Component::start()
{
	m_hasStarted = true;
	onStart();

}

void GameCore::Component::update(float deltaTime)
{
	onUpdate(deltaTime);
}

//Used to update physics
void GameCore::Component::fixedUpdate(float fixedFrameRate)
{
	onFixedUpdate(fixedFrameRate);
}

void GameCore::Component::draw()
{
	onDraw();
}

void GameCore::Component::end()
{
	onEnd();
}
