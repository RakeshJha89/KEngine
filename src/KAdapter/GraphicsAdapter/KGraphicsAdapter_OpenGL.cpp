
#include "KMacro.h"
#include "KTypes.h"
#include "KGraphicsAdapter_OpenGL.h"

//#if KARMA_USE_GL


namespace Karma
{
	GraphicsAdapter_OpenGL::GraphicsAdapter_OpenGL()
	{
	}

	bool GraphicsAdapter_OpenGL::Initialize()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		//Do Initializations

		//-------------------

		// Create a GLFWwindow object that we can use for GLFW's functions
		m_hwndWindow = glfwCreateWindow(WIDTH, HEIGHT, "KarmaEngine v 1.0.0", nullptr, nullptr);
		if (m_hwndWindow == nullptr)
		{
			printf("\nFailed to create GLFW window");
			return false;
		}
		glfwMakeContextCurrent(m_hwndWindow);

		// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
		glewExperimental = GL_TRUE;
		// Initialize GLEW to setup the OpenGL Function pointers
		if (glewInit() != GLEW_OK)
		{
			printf("\nFailed to initialize GLEW");
			return false;
		}


		// Define the viewport dimensions
		int width, height;
		glfwGetFramebufferSize(m_hwndWindow, &width, &height);
		glViewport(0, 0, width, height);

		//Register Callbacks;
		glfwSetKeyCallback(m_hwndWindow, &GraphicsAdapter_OpenGL::OnKeyboardEvents);

		return true;
	}

	bool GraphicsAdapter_OpenGL::Update(float _dt)
	{
		if (glfwWindowShouldClose(m_hwndWindow))
			return false;

		//Later move this call to Input handler.
		glfwPollEvents();

		// Rendering commands here
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap the screen buffers
		glfwSwapBuffers(m_hwndWindow);
		
		return true;
	}

	bool GraphicsAdapter_OpenGL::Terminate()
	{
		glfwTerminate();
		return true;
	}

	void GraphicsAdapter_OpenGL::OnKeyboardEvents(GLFWwindow* window, int key, int scancode, int action, int mode)
	{
		// When a user presses the escape key, we set the WindowShouldClose property to true, 
		// closing the application
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
//#endif