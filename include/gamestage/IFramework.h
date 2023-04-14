// underlying windowing/input management framework
// Windows, Mac, Linux, (NX?) : SDL2
#ifndef GAMESTAGE_IFRAMEWORK_H
#define GAMESTAGE_IFRAMEWORK_H

// Application is currently using OpenGL for rendering
#define GAMESTAGE_GAPI_GL 0
// Application is currently using OpenGL|ES for rendering (Unsupported!)
#define GAMESTAGE_GAPI_GLES 1
// Application is currently using Vulkan for rendering (Unsupported!)
#define GAMESTAGE_GAPI_VULKAN 2
// Application is currently using DirectX11 for rendering (Unsupported!)
#define GAMESTAGE_GAPI_DX11 3
// Application is currently using DirectX12 for rendering (Unsupported!)
#define GAMESTAGE_GAPI_DX12 4

#include "gamestage/IInputManager.h"

class IFramework {
    public:
        virtual void CreateWindow() = 0;
        virtual void DestroyWindow() = 0;
        virtual bool Running() = 0;
        virtual void PumpEvents() = 0;
        virtual IInputManager* GetInputManager() = 0;
        // OpenGL only: defines how buffer swapping is managed for presenting a frame to the screen
        virtual void GLSwapBuffer() = 0;
    private:
        // see defines in IFramework.hpp
        int _api;
};

#endif