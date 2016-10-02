
#include "precompiled_Core.h"

#include "kAppFramework_Windows.h"

#include "TimerAdapter/KTimerAdapter.h"
#include "GraphicsAdapter/KGraphicsAdapter.h"

#include "KSingletonManager.h"
#include "KAdapterFactory.h"
#include "KComponent_Transform.h"

namespace Karma
{
    kAppFramework_Windows::kAppFramework_Windows()
    :	m_IsExitRequested(false)
    {
    }

    int kAppFramework_Windows::Initialize()
    {
        /*SINGLETON_MANAGER.SetTimerAdapter(new TimerAdapter_Windows());
        SINGLETON_MANAGER.SetGraphicsAdapter(new GraphicsAdapter_OpenGL());*/

        SINGLETON_MANAGER.Initialize();
        SINGLETON_MANAGER.GetTimerAdapter()->Initialize();
        SINGLETON_MANAGER.GetGraphicsAdapter()->Initialize();

        return 1;
    }

    int kAppFramework_Windows::Update()
    {
        TimerAdapter* gameTimer = TIMER_ADAPTER;
        double LastTime = gameTimer->GetCurrentTimeInSeconds();
        double timeToCatchup = 0.0;
        double fps = 1 / 60.0f; //FPS.

        while (!m_IsExitRequested)
        {
            gameTimer->SetPreviousTime(gameTimer->GetCurrTime());
            gameTimer->SetCurrentTime(gameTimer->GetCurrentTimeInSeconds());

            double deltaTime = gameTimer->GetCurrTime() - LastTime;

            timeToCatchup += deltaTime;

            gameTimer->SetDeltaTime(deltaTime);

            bool isExitRequested = false;
            while (timeToCatchup >= fps)
            {
                DEBUGOUT("dt => "); DEBUGOUT(timeToCatchup); DEBUGOUT("\n");
                isExitRequested = !GRAPHICS_ADAPTER->Update((float)timeToCatchup);
                timeToCatchup -= fps;
            }
            LastTime = gameTimer->GetCurrTime();

            m_IsExitRequested = isExitRequested;
        }
        return 1;
    }

    int kAppFramework_Windows::Terminate()
    {
        SINGLETON_MANAGER.GetGraphicsAdapter()->Terminate();
        return 1;
    }
}
