/**************************************************************************************************
KarmaEngine (OpenGL)
File Created/Modified On: "02/09/2016"
File Created by: "Rakesh Jha"
All rights reserved.
***************************************************************************************************/

#pragma once

namespace Karma
{
	class kAppFramework
	{
	public:
		virtual int Initialize() = 0;
		virtual int Update() = 0;
		virtual int Terminate() = 0;
	};
}


