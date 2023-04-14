#ifndef GAMESTAGE_SPRITE_H
#define GAMESTAGE_SPRITE_H

#include "gamestage/Video/Texture.h"

class Sprite {
    public:
        Sprite();
        ~Sprite();

        void SetTexture(Texture* texture);
        Texture* GetTexture();
};

#endif