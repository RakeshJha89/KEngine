/**************************************************************************************************
KarmaEngine (OpenGL)
File Created/Modified On: "02/09/2016"
File Created by: "Rakesh Jha"
All rights reserved.
***************************************************************************************************/

#pragma once
#define GLEW_STATIC
#include "glew.h"
#include "glfw3.h"
#include "KGraphicsAdapter.h"

namespace Karma
{
	class GraphicsAdapter_OpenGL : public GraphicsAdapter
	{
	public:
		GraphicsAdapter_OpenGL();
		virtual ~GraphicsAdapter_OpenGL() {}

		virtual bool Initialize() override;
		virtual bool Update(float _dt) override;
		virtual bool Terminate() override;


	private:
		static void OnKeyboardEvents(GLFWwindow* window, int key, int scancode, int action, int mode);

		GLFWwindow* m_hwndWindow;
	};
}