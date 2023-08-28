#pragma once
#include "GameCore/TransformComponent.h"
#include "Vector4.h"

namespace GameGraphics
{
	class CircleComponent :
		public GameCore::TransformComponent
	{
	public:
		//the stats the of the circle component
		CircleComponent(float radius = 5.0f, GameMath::Vector4 color = {1.0f, 1.0f, 1.0f, 1.0f});

		
		void onDraw() override;

		//gets the color
		GameMath::Vector4 getColor() { return m_color; }
		/// <summary>
		/// sets the color
		/// </summary>
		/// <param name="color"></param>
		void setColor(GameMath::Vector4 color) { m_color = color; }

	private:
		float m_raidus;
		GameMath::Vector4 m_color;

	};
}


