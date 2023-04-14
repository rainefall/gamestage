#ifndef GAMESTAGE_API_H
#define GAMESTAGE_API_H

#ifndef GAMESTAGE_STATIC_LINK
    #ifdef _WIN32
        #ifdef GAMESTAGE_EXPORTS
            #define GAMESTAGE_API __declspec( dllexport )
        #else
            #define GAMESTAGE_API __declspec( dllimport )
        #endif
    #else
        #define GAMESTAGE_API
    #endif
#else
    #define GAMESTAGE_API
#endif

#include "gamestage/IVideo.h"
#include "gamestage/IFramework.h"
#include "gamestage/IInputManager.h"

#endif