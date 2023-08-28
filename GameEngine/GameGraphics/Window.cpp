#include "pch.h"
#include "Window.h"
#include "raylib.h"

GameGraphics::Window::Window(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;
}

 //closes the window
bool GameGraphics::Window::shouldClose()
{
	return WindowShouldClose();
}

//Gets the time of the window
float GameGraphics::Window::getDeltaTime()
{
	return GetFrameTime();
}

//gets the frame rate for the widndow
int GameGraphics::Window::getFrameRate()
{
	return	GetFPS();
}

//sets the frame rate of the window
void GameGraphics::Window::setFrameRate(int frameRate)
{
	SetTargetFPS(frameRate);
}

//opens the window
void GameGraphics::Window::open()
{
	InitWindow(m_width, m_height, m_title);
	m_isOpen = true;
	SetTargetFPS(60);
}

//draws the window
void GameGraphics::Window::beginDraw()
{
	BeginDrawing();
	ClearBackground(BLACK);
}

//stops drawing the window
void GameGraphics::Window::endDraw()
{
	EndDrawing();
}

//closes the window
void GameGraphics::Window::close()
{
	CloseWindow();
	m_isOpen = true;
}
