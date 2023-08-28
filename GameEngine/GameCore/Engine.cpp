#include "pch.h"
#include "Engine.h"
#include "GameGraphics/Window.h"
#include "Scene.h"



GameCore::Engine::Engine(int windowWidth, int windowHeight, const char* windowName, int windowFrameRate, int fixedFrameRate, int accumulatedTime)
{

	//All the variables needed to create a window
	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;
	m_windowName = windowName;
	m_windowFrameRate = windowFrameRate;
	m_fixedFrameRate = fixedFrameRate;
}

GameCore::Engine::~Engine()
{
	//deletes the window
	delete m_window;
	m_window = nullptr;
}

void GameCore::Engine::run()
{
	//Game loop
	start();

	//while the window is open...
	while (!m_window->shouldClose())
	{
		//...calculate the time
		float deltaTime = m_window->getDeltaTime();
		float fixedDeltaTime(1.0f / m_fixedFrameRate);
		m_accumulatedTime += deltaTime;
		
		//update	
		update(deltaTime);
		
		//Fixed update
		while (m_accumulatedTime >= fixedDeltaTime)
		{
			fixedUpdate(fixedDeltaTime);
			m_accumulatedTime -= fixedDeltaTime;
		}
		//Draw
		draw();
	}
	
	end();
}

//on start is sets the windows height and width and opening the window and setting the desired frame rate
void GameCore::Engine::start()
{
	m_window = new GameGraphics::Window(m_windowWidth, m_windowHeight, m_windowName);
	m_window->open();
	m_window->setFrameRate(m_windowFrameRate);
}

void GameCore::Engine::update(float deltaTime)
{
	if (m_currentScene)
		m_currentScene->update(deltaTime);
}

void GameCore::Engine::fixedUpdate(float fixedDeltaTime)
{
	//Call the current scenes fixed update
	if (m_currentScene)
	{
		m_currentScene->fixedUpdate(fixedDeltaTime);
	}
	
}

void GameCore::Engine::draw()
{
	m_window->beginDraw();

	if (m_currentScene)
		m_currentScene->draw();

	m_window->endDraw();
}

void GameCore::Engine::end()
{
	m_window->close();
}
