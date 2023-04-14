#ifndef GAMESTAGE_IVIDEO_H
#define GAMESTAGE_IVIDEO_H

#include "gamestage/IFramework.h"
#include "gamestage/Video/Sprite.h"

class IVideo {
    public:
        virtual void Initialise(IFramework* framework) = 0;
        virtual void Shutdown() = 0;

        virtual void DrawSprite(Sprite* spr) = 0;
        virtual void DrawVertexBuffer() = 0;

        virtual void ClearBuffers() = 0;
        virtual void PresentFrame() = 0;
    private:
        IFramework* _framework;
};

#endif