#include "InteractiveUIElement.h"

void InteractiveUIElement::Reset() {
    sprite.setTextureRect(spriteRect);
}
    
void InteractiveUIElement::setPressedTexture() {
    sprite.setTextureRect(spriteRectPressed);
}