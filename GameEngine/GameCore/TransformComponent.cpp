#include "pch.h"
#include "TransformComponent.h"

GameMath::Matrix4 GameCore::TransformComponent::getGlobalMatrix()
{
	//updateGloabalMatrix();
	updateMatrices();
	return m_globalMatrix;
}

GameMath::Matrix4 GameCore::TransformComponent::getlocalMatrix()
{
	//updateLocalMatrix();
	updateMatrices();
	return m_localMatrix;
}

void GameCore::TransformComponent::setLocalPosition(GameMath::Vector3 position)
{
	m_translation = position;
	//m_shouldUpdateLocal = true;
	//m_shouldUpdateMatrices = true;
}


GameMath::Vector3 GameCore::TransformComponent::getLocalPosition()
{
	
	return m_translation;
}

GameMath::Vector3 GameCore::TransformComponent::getGlobalPosition()
{
	//updateGloabalMatrix();
	updateMatrices();
	return GameMath::Vector3(m_globalMatrix.m03, m_globalMatrix.m13, m_globalMatrix.m23);
}

void GameCore::TransformComponent::setLocalRotation(GameMath::Vector3 rotation)
{
	m_rotation = rotation;
	//m_shouldUpdateLocal = true;
	//m_shouldUpdateMatrices = true;
}

GameMath::Vector3 GameCore::TransformComponent::getLocalRotaion()
{
	
	return m_rotation;
}

void GameCore::TransformComponent::setLocalScale(GameMath::Vector3 scale)
{
	m_scale = scale;
	//m_shouldUpdateLocal = true;
	//m_shouldUpdateMatrices = true;
}

GameMath::Vector3 GameCore::TransformComponent::getLocalScale()
{
	return m_scale;
}

void GameCore::TransformComponent::setParent(TransformComponent* parent)
{   
	m_parent = parent;
}

GameCore::TransformComponent* GameCore::TransformComponent::getParent()
{
	return m_parent;
}

void GameCore::TransformComponent::updateMatrices()
{
	//if (!m_shouldUpdateMatrices)
		//return;

	//Create translation matrix
	GameMath::Matrix4 translation = GameMath::Matrix4::createTranslation(m_translation);
	//create rotation matrix
	GameMath::Matrix4 rotation = GameMath::Matrix4::createRotationX(m_rotation.x)
		* GameMath::Matrix4::createRotationY(m_rotation.y)
		* GameMath::Matrix4::createRotationZ(m_rotation.z);
	//create scale matrix
	GameMath::Matrix4 scale = GameMath::Matrix4::createScale(m_scale);


	//Calculate the local matrix
	m_localMatrix = translation * rotation * scale;

	//calculate the global matrix
	if (m_parent)
	{
		m_globalMatrix = m_parent->getGlobalMatrix() * m_localMatrix;
	}
	else
	{
		m_globalMatrix = m_localMatrix;
	}

	//unflag matrices for update
	//m_shouldUpdateMatrices = false;
}

//void GameCore::TransformComponent::updateLocalMatrix()
//{
//	if (!m_shouldUpdateLocal)
//		return;
//
//	//Create translation matrix
//	GameMath::Matrix4 translation = GameMath::Matrix4::createTranslation(m_translation);
//	//create rotation matrix
//	GameMath::Matrix4 rotation = GameMath::Matrix4::createRotationX(m_rotation.x)
//		* GameMath::Matrix4::createRotationY(m_rotation.y)
//		* GameMath::Matrix4::createRotationZ(m_rotation.z);
//	//create scale matrix
//	GameMath::Matrix4 scale = GameMath::Matrix4::createScale(m_scale);
//
//
//	//Calculate the local matrix
//	m_localMatrix = translation * rotation * scale;
//
//	//Flag global matrices for update
//	m_shouldUpdateGlobal = true;
//	
//	
//
//	m_shouldUpdateLocal = false;
//}
//
//void GameCore::TransformComponent::updateGloabalMatrix()
//{
//	//Ensure local matrix is up to date
//	updateLocalMatrix();
//
//	if (!m_shouldUpdateGlobal)
//		return;
//
//	//calculate the global matrix
//	if (m_parent)
//		m_globalMatrix = m_parent->getGlobalMatrix() * m_localMatrix;
//	else
//		m_globalMatrix = m_localMatrix;
//	
//	//Flag child matrices for update
//	for (TransformComponent* child : m_children)
//	{
//		child->m_shouldUpdateGlobal = true;
//	
//	}
//	m_shouldUpdateGlobal = false;
//}
