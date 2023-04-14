#include <SDL.h>
#include "gamestage/api.h"

class Framework_SDL : public IFramework {
    public:
        GAMESTAGE_API void CreateWindow();
        GAMESTAGE_API void DestroyWindow();
        GAMESTAGE_API bool Running();
        GAMESTAGE_API void PumpEvents();
        GAMESTAGE_API IInputManager* GetInputManager();
        GAMESTAGE_API void GLSwapBuffer();
    private:
        SDL_Window* _window;
        bool _running = true;
};

extern "C" GAMESTAGE_API IFramework* get_framework_api();