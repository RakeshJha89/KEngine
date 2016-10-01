/**************************************************************************************************
KarmaEngine (OpenGL)
File Created/Modified On: "02/09/2016"
File Created by: "Rakesh Jha"
All rights reserved.
***************************************************************************************************/
#pragma once

//#include "KMemory.h" // Uncomment when the memory management is done.
#include "kAppFramework_Windows.h"
using namespace Karma;

int main()
{
    //TODO: All new and delete will be replaced by a memory manager. Create factory.
    kAppFramework_Windows* app = new kAppFramework_Windows();
    if (app->Initialize())
    {
        app->Update();
    }
    app->Terminate();

    delete app;

    return 0;
}