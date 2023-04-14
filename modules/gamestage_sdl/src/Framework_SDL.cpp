#include "gamestage/Framework_SDL.h"

void Framework_SDL::CreateWindow() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
    }

    _window = SDL_CreateWindow(GAMESTAGE_EXE_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, SDL_WINDOW_RESIZABLE);
    if (!_window) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s", SDL_GetError());
    }
}

bool Framework_SDL::Running() {
    return _running;
}

void Framework_SDL::PumpEvents() {
    SDL_PumpEvents();
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
        switch (e.type)
        {
        case SDL_QUIT:
            _running = false;
            break;
        
        default:
            break;
        }
    }
}

IInputManager* Framework_SDL::GetInputManager() {
    return nullptr;
}

void Framework_SDL::DestroyWindow() {
    SDL_DestroyWindow(_window);
}

void Framework_SDL::GLSwapBuffer() {
    //SDL_GL_SwapWindow(_window);
}

extern "C" GAMESTAGE_API IFramework* get_framework_api() {
    return new Framework_SDL();
}