/**************************************************************************************************
KarmaEngine (OpenGL)
File Created/Modified On: "02/09/2016"
File Created by: "Rakesh Jha"
All rights reserved.
***************************************************************************************************/

#pragma once
#include "KSingletonTemplate.h"

namespace Karma
{
	class TimerAdapter /*: public SingletonTemplate<TimerAdapter>*/
	{
	public:
		TimerAdapter() {};
		virtual ~TimerAdapter() {}

		virtual void Initialize() {};
		virtual void SetCurrentTime(double val) {};
		virtual void SetPreviousTime(double val) {};
		virtual void SetDeltaTime(double val) {};
		virtual void SetFixedDelta(double val) {};

		virtual double GetCurrTime()  const { return 0.0f; }
		virtual double GetPrevTime()  const { return 0.0f; }
		virtual double GetDeltaTime()  const { return 0.0f; }
		virtual double GetFixedDelta()  const { return 0.0f; }
		virtual double GetCurrentTimeInSeconds() { return 0.0f; }

	private:
		virtual double SetSecondsPerTick() { return 0.0f; }
	};
}
