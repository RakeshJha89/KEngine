/**************************************************************************************************
KarmaEngine (OpenGL)
File Created/Modified On: "02/09/2016"
File Created by: "Rakesh Jha"
All rights reserved.
***************************************************************************************************/

#pragma once
#include <map>

namespace Karma
{
	class GraphicsAdapter;
	class TimerAdapter;

	class SingletonManager
	{
	private:
		TimerAdapter*		m_gameTimer;
		GraphicsAdapter*	m_graphicsAdapter;
		
		static SingletonManager m_this;

	public:
		virtual void		Initialize();
		static SingletonManager&	GetInstance() { return m_this; }

		TimerAdapter*		GetTimerAdapter() const { return m_gameTimer; }
		GraphicsAdapter*	GetGraphicsAdapter() const { return m_graphicsAdapter; }

		void				SetTimerAdapter(TimerAdapter* _timerAdapter) { m_gameTimer = _timerAdapter; }
		void				SetGraphicsAdapter(GraphicsAdapter* _graphicsAdapter)	{ m_graphicsAdapter = _graphicsAdapter; }


	};

#define SINGLETON_MANAGER SingletonManager::GetInstance()
#define GRAPHICS_ADAPTER	SINGLETON_MANAGER.GetGraphicsAdapter()
#define TIMER_ADAPTER		SINGLETON_MANAGER.GetTimerAdapter()
}