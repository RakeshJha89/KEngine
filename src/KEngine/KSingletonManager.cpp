
#include "KSingletonManager.h"

namespace Karma
{
	SingletonManager SingletonManager::m_this;

	void SingletonManager::Initialize()
	{
		//Initialize all systems here.
		m_gameTimer = nullptr;
		m_graphicsAdapter = nullptr;
	}
}