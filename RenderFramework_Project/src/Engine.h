//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
//----------------------------------------------------------------------------

#ifndef ENGINE_H
#define ENGINE_H

#ifdef WIN32
    #pragma once
    #define _CRT_SECURE_NO_WARNINGS 1

    #define WIN32_LEAN_AND_MEAN 1

#pragma warning( push )
	#pragma warning( disable : 4255 )
	#pragma warning( disable : 4820 )
	#pragma warning( disable : 4668 )
	#pragma warning( disable : 5039 )
	#include <windows.h>
#pragma warning( pop )

#else
    #include <unistd.h>
    #define Sleep(t) sleep(t)
#endif

#include "GL/gl3w.h"

#define GLFW_NO_GLU 1
#define GLFW_INCLUDE_GLCOREARB 1

#include "GLFW/glfw3.h"

#include "sb7ext.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

#define UNUSED_VAR(x) (void)x // Keenan

class Engine
{
private:
	static void APIENTRY debug_callback(GLenum source,
										GLenum type,
										GLuint id,
										GLenum severity,
										GLsizei length,
										const GLchar* message,
										GLvoid* userParam);

public:
	Engine(const char* windowName, const int Width, const int Height);
	Engine() = delete;
	virtual ~Engine();

	//virtual void run(Engine* the_app);
	void run();

	virtual void Initialize();
	virtual void LoadContent() = 0;
	virtual void CreateScene() {};
	virtual void Update(float currentTime) = 0;
	virtual void Draw() = 0;
	virtual void UnLoadContent();

	// optional overloading
	virtual void ClearBufferFunc();

	int GetKey(int key);                          //Keenan(23)
	int GetMouseButton(int button);               // Keenan(24)
	void GetCursorPos(float &xPos, float &yPos);  // Keenan(24)
private:
	void privPreInitialize();
	void privPreLoadContent();

public:
	void setWindowTitle(const char * title)
	{
		glfwSetWindowTitle(window, title);
	}

	virtual void onResize(int w, int h)
	{
		info.windowWidth = w;
		info.windowHeight = h;
}

	virtual void onKey(int key, int action)
	{
		UNUSED_VAR(key);
		UNUSED_VAR(action);
	}

	virtual void onMouseButton(int button, int action)
	{
		UNUSED_VAR(button);
		UNUSED_VAR(action);
	}

	virtual void onMouseMove(int x, int y)
	{
		UNUSED_VAR(x);
		UNUSED_VAR(y);
	}

	virtual void onMouseWheel(int pos)
	{
		UNUSED_VAR(pos);
	}

	virtual void onDebugMessage(GLenum source,
								GLenum type,
								GLuint id,
								GLenum severity,
								GLsizei length,
								const GLchar* message)
	{
		UNUSED_VAR(length);
		UNUSED_VAR(severity);
		UNUSED_VAR(id);
		UNUSED_VAR(type);
		UNUSED_VAR(source);

#ifdef _WIN32
		OutputDebugStringA(message);
		OutputDebugStringA("\n");
#endif /* _WIN32 */
	}

	void getMousePosition(int& x, int& y)
	{
		double dx, dy;
		glfwGetCursorPos(window, &dx, &dy);

		x = static_cast<int>(floor(dx));
		y = static_cast<int>(floor(dy));
	}

public:
	struct APPINFO
	{
		char title[128];
		int windowWidth;
		int windowHeight;
		int majorVersion;
		int minorVersion;
		int samples;
		union
		{
			struct
			{
				unsigned int    fullscreen : 1;
				unsigned int    vsync : 1;
				unsigned int    cursor : 1;
				unsigned int    stereo : 1;
				unsigned int    debug : 1;
				unsigned int    robust : 1;
			};
			unsigned int        all;
		} flags;
	};

protected:
	APPINFO     info;
	static      Engine * app;
	GLFWwindow* window;

	static void glfw_onResize(GLFWwindow* window, int w, int h)
	{
		UNUSED_VAR(window);

		app->onResize(w, h);
	}

	static void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		UNUSED_VAR(mods);
		UNUSED_VAR(scancode);
		UNUSED_VAR(window);

		app->onKey(key, action);
	}

	static void glfw_onMouseButton(GLFWwindow* window, int button, int action, int mods)
	{
		UNUSED_VAR(mods);
		UNUSED_VAR(window);

		app->onMouseButton(button, action);
	}

	static void glfw_onMouseMove(GLFWwindow* window, double x, double y)
	{
		UNUSED_VAR(window);

		app->onMouseMove(static_cast<int>(x), static_cast<int>(y));
	}

	static void glfw_onMouseWheel(GLFWwindow* window, double xoffset, double yoffset)
	{
		UNUSED_VAR(window);
		UNUSED_VAR(xoffset);

		app->onMouseWheel(static_cast<int>(yoffset));
	}

	void setVsync(bool enable)
	{
		info.flags.vsync = enable ? 1u : 0u;
		glfwSwapInterval((int)info.flags.vsync);
	}
};

#endif 

// ---  End of File ---------------