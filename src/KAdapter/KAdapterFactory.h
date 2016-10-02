#pragma once

//#ifdef WIN_32
#include "GraphicsAdapter/KGraphicsAdapter_OpenGL.h"
#include "TimerAdapter/KTimerAdapter_Windows.h"
//#endif


class AdapterFactory
{
    enum FactoryPlatformType
    {
        Editor,
        Windows,
        PS4,
        XONE
    };

public:

    void CreateFactoryObjects(FactoryPlatformType type)
    {
        switch (type)
        {
        case Editor:
            SINGLETON_MANAGER.SetTimerAdapter(new TimerAdapter_Windows());
            SINGLETON_MANAGER.SetGraphicsAdapter(new GraphicsAdapter_OpenGL());
            break;
        case Windows:
        case PS4:
        case XONE:
        default:
            break;
        }
    }

};