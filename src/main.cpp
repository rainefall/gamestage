#include "gamestage/api_loaders.h"

// Entry point
int main(int argc, char* argv[]) {
	IFramework* engine = gamestage_GetFrameworkAPI();
    engine->CreateWindow();

    while(engine->Running()) {
        engine->PumpEvents();
        engine->GLSwapBuffer();
    }

    engine->DestroyWindow();
}