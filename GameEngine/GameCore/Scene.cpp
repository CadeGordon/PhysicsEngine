#include "pch.h"
#include "Scene.h"
#include <iostream>
#include "Entity.h"
#include "GamePhysics/ColliderComponent.h"
#include "GamePhysics/RigidBodyComponent.h"

GameCore::Scene::Scene()
{
}

void GameCore::Scene::start()
{
	m_hasStarted = true;
	onStart();
}

void GameCore::Scene::update(float deltaTime)
{
	if (!m_hasStarted)
	{
		start();
	}


	for (Entity* entity : m_entities)
	{
		entity->update(deltaTime);
	}

	onUpdate(deltaTime);

	

}

void GameCore::Scene::fixedUpdate(float fixedFrameRate)
{
	onFixedUpdate(fixedFrameRate);

	for (Entity* entity : m_entities)
		entity->fixedUpdate(fixedFrameRate);

	//Check collisions
	for (auto row = m_collider.begin(); row != m_collider.end(); row++)
	{
		for (auto column = row; column != m_collider.end(); column++)
		{
			if (row != column)
			{
				if ((*row)->checkCollision(*column))
				{
					(*row)->getOwner()->collision((*column)->getOwner());

					if (GameMath::Vector3::dotProduct((*row)->getOwner()->getComponent<GamePhysics::RigidBodyComponent>()->getVelocity(),
					    (*column)->getOwner()->getComponent<GamePhysics::RigidBodyComponent>()->getVelocity()) > 0) {
					    //(column)->getOwner()->collision((row)->getOwner());
					}
					
					//(*row)->getOwner()->collision((*column)->getOwner());
					//(*column)->getOwner()->collision();
				}
			}
		}
	}
}

void GameCore::Scene::draw()
{
	onDraw();

	for (Entity* entity : m_entities)
	{
		entity->draw();
	}
}

void GameCore::Scene::close()
{
	onEnd();
}

void GameCore::Scene::add(Entity* entity)
{
	//If the entity already has an scene
	//remove it from that scene
	if (Scene* oldScene = entity->getScene())
	{
		oldScene->remove(entity);
	}
	//Add the entity to this scenes list
	m_entities.add(entity);
	//set the entities scenes's to this scene
	entity->setScene(this);
	entity->added();
}

void GameCore::Scene::remove(Entity* entity)
{
	entity->removed();
	//Removes the entity from this scenes lists
	m_entities.remove(entity);
	//nullify the entities scenes
	entity->setScene(nullptr);
}


//adds a collider to the scene
void GameCore::Scene::addCollider(GamePhysics::ColliderComponent* collider)
{
	m_collider.add(collider);
}

//removes the collider from the scene
void GameCore::Scene::removeCollider(GamePhysics::ColliderComponent* collider)
{
	m_collider.add(collider);
}
