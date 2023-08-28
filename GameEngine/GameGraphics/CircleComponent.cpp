#include "pch.h"
#include "CircleComponent.h"
#include "raylib.h"

GameGraphics::CircleComponent::CircleComponent(float radius, GameMath::Vector4 color)
{
	m_raidus = radius;
	m_color = color;
}

void GameGraphics::CircleComponent::onDraw()
{
	//store the postion
	GameMath::Vector3 position = getGlobalPosition();
	//store the color for raylib
	Color color = { m_color.x * 255, m_color.y * 255, m_color.z * 255, m_color.w * 255 };
	//Draw the circle
	DrawCircle((int)position.x, -(int)position.y + GetScreenHeight(), m_raidus, color);
}

