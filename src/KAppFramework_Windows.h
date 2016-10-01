/**************************************************************************************************
KarmaEngine (OpenGL)
File Created/Modified On: "02/09/2016"
File Created by: "Rakesh Jha"
All rights reserved.
***************************************************************************************************/

#pragma once
#include "kAppFramework.h"

namespace Karma
{
	class kAppFramework_Windows : public kAppFramework
	{
	public:
		kAppFramework_Windows();
		virtual ~kAppFramework_Windows() {}

		int Initialize() override;
		int	Update() override;
		int Terminate() override;

	protected:
		bool m_IsExitRequested;
	};
}

