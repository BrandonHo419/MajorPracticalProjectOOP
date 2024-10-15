#include "Scroll.h"

void Scroll::Reset() {
    sprite.setTextureRect(spriteRect);
}

void Scroll::setPressedTexture() {
    sprite.setTextureRect(spriteRectPressed);
}