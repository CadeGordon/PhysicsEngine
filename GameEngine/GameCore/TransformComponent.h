#pragma once
#include "Component.h"
#include "Vector3.h"
#include "List.h"
#include "Matrix4.h"
#include "Matrix3.h"


namespace GameCore
{
	class TransformComponent : public Component
	{
	public:
		TransformComponent() {}

		GameMath::Matrix4 getGlobalMatrix();
		GameMath::Matrix4 getlocalMatrix();
		
		void setLocalPosition(GameMath::Vector3 position);
		GameMath::Vector3 getLocalPosition();

		//void setGlobalPosition(GameMath::Vector3 position);
		GameMath::Vector3 getGlobalPosition();

		//this is in radians
		void setLocalRotation(GameMath::Vector3 rotation);
		GameMath::Vector3 getLocalRotaion();

		void setLocalScale(GameMath::Vector3 scale);
		GameMath::Vector3 getLocalScale();

		void setParent(TransformComponent* parent);
		TransformComponent* getParent();


	private:
		//void updateLocalMatrix();
		//void updateGloabalMatrix();
		void updateMatrices();

	private:
		GameMath::Matrix4 m_globalMatrix;
		GameMath::Matrix4 m_localMatrix;

		GameMath::Vector3 m_translation = GameMath::Vector3({0.0f, 0.0f, 0.0f});
		GameMath::Vector3 m_rotation = GameMath::Vector3({0.0f, 0.0f, 0.0f});
		GameMath::Vector3 m_scale = GameMath::Vector3({1.0f, 1.0f, 1.0f});

		TransformComponent* m_parent = nullptr;

		//bool m_shouldUpdateLocal = true;
		//bool m_shouldUpdateGlobal = true;
		//bool m_shouldUpdateMatrices = true;

	};
}


