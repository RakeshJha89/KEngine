/**************************************************************************************************
KarmaEngine (OpenGL)
File Created/Modified On: "02/09/2016"
File Created by: "Rakesh Jha"
All rights reserved.
***************************************************************************************************/

#pragma once
#include "KSingletonTemplate.h"
#include "KShaderManager.h"

namespace Karma
{
	class GraphicsAdapter : public SingletonTemplate<GraphicsAdapter>
	{
	public:
		GraphicsAdapter() {}
		virtual ~GraphicsAdapter() {}

		virtual bool Initialize() { return true; };
		virtual bool Update(float _dt) { return true; };
		virtual bool Terminate() { return true; };

	private:
		ShaderManager m_shaderManager;
	};
}

