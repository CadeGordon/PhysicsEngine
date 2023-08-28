#pragma once

namespace GameGraphics
{
	class Window;
}


namespace GameCore 
{
	class Scene;

	/// <summary>
	/// A class that manages the entire game. Calls run() to begin.
	/// </summary>
	class Engine
	{
	public:
		Engine(int windowWidth = 800, int windowHeight = 600, const char* windowName = "CryoGame", int windowFrameRate = 60, int fixedFrameRate = 30, int accumulatedTime = 0);
		~Engine();

		/// <summary>
		/// Begins the games.
		/// </summary>
		void run();

		/// <summary>
		/// Sets the current scene
		/// </summary>
		/// <param name="scene"></param>
		void setCurrentScene(Scene* scene) {m_currentScene = scene;}
		/// <summary>
		/// gets the current scene
		/// </summary>
		/// <returns>m_currentScene</returns>
		Scene* getCurrentScene() { return m_currentScene; }

	private:
		//Called before the first update function
		void start();
		//Called after the first start call
		void update(float deltaTime);
		//handles all the physics updates
		void fixedUpdate(float fixedDeltaTime);
		void draw();
		void end();

	private:
		//gets the window
		GameGraphics::Window* m_window = nullptr;
		//the settings for the window
		int m_windowWidth, m_windowHeight, m_windowFrameRate;
		//set window name
		const char* m_windowName;
		//set frame rate
		int m_fixedFrameRate;
		// the current scene
		Scene* m_currentScene = nullptr;
		// the time
		float m_accumulatedTime = 0.0f;
	};
}


