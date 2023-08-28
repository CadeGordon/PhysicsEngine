#pragma once



namespace GameGraphics
{
	class Window
	{
	public:
		Window(int width, int height, const char* title = "Window");

		bool shouldClose();
		float getDeltaTime();
		/// <summary>
		/// Get the current frame rate for this window
		/// </summary>
		/// <returns>the current frame rate of this window</returns>
		int getFrameRate();
		/// <summary>
		/// Sets the target framerate for this window
		/// </summary>
		/// <param name="Frames per second">the frame rate in frames per second</param>
		void setFrameRate(int frameRate);

		/// <summary>
		/// tells the window to open
		/// </summary>
		void open();
		/// <summary>
		/// draws the window
		/// </summary>
		void beginDraw();
		/// <summary>
		/// stops drawing the window
		/// </summary>
		void endDraw();
		void draw();
		void close();

	private:
		int m_width, m_height;
		const char* m_title;
		bool m_isOpen = false;
	};
}


