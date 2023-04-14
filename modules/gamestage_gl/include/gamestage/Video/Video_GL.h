#ifndef GAMESTAGE_VIDEO_GL_H
#define GAMESTAGE_VIDEO_GL_H

#include "gamestage/api.h"
#include "gamestage/Video/Sprite.h"

class Video_GL : public IVideo {
    public:
        GAMESTAGE_API void Initialise(IFramework* framework);
        GAMESTAGE_API void Shutdown();

        GAMESTAGE_API void DrawSprite(Sprite* spr);
};

extern "C" GAMESTAGE_API IVideo* get_video_api();

#endif