
#include "KTimerAdapter_Windows.h"
#include "KMacro.h"

namespace Karma
{
	TimerAdapter_Windows::TimerAdapter_Windows()
	{
	}

	void TimerAdapter_Windows::Initialize()
	{
		SetSecondsPerTick();
	}

	double TimerAdapter_Windows::SetSecondsPerTick()
	{
		if (m_secondsPerTick <= 0)
		{
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			m_secondsPerTick = 1.0 / frequency.QuadPart;
		}
		return m_secondsPerTick;
	}

	double TimerAdapter_Windows::GetCurrentTimeInSeconds()
	{
		LARGE_INTEGER Cycles;
		QueryPerformanceCounter(&Cycles);

		return Cycles.QuadPart * m_secondsPerTick;
	}
}
