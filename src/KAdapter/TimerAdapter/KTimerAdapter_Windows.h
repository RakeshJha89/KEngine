/**************************************************************************************************
KarmaEngine (OpenGL)
File Created/Modified On: "02/09/2016"
File Created by: "Rakesh Jha"
All rights reserved.
***************************************************************************************************/

#pragma once
#include "KTimerAdapter.h"

namespace Karma
{
	class TimerAdapter_Windows : public TimerAdapter
	{
	public:
		TimerAdapter_Windows();
		virtual ~TimerAdapter_Windows() {}
		void Initialize() override;
		void SetCurrentTime(double val) override { m_currTime = val; }
		void SetPreviousTime(double val) override { m_prevTime = val; }
		void SetDeltaTime(double val) override { m_deltaTime = val; }
		void SetFixedDelta(double val) override { m_fixedDeltaTime = val; }

		double GetCurrTime() const { return m_currTime; }
		double GetPrevTime() const { return m_prevTime; }
		double GetDeltaTime() const { return m_deltaTime; }
		double GetFixedDelta() const { return m_fixedDeltaTime; }

		double GetCurrentTimeInSeconds();
	
	private:
		virtual double SetSecondsPerTick();

		double m_secondsPerTick;
		double m_currTime;
		double m_prevTime;
		double m_deltaTime;
		double m_fixedDeltaTime;
	};
}

