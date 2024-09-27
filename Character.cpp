#include "Character.h"

Character::Character(const sf::Vector2f& position): position(position) {
    // Walking animations
    animations[int(indexAnimation::Upwards)] = Animation(64, 64*8, 64, 64, 8, 0);
    animations[int(indexAnimation::Left)] = Animation(64, 64*9, 64, 64, 8, 0);
    animations[int(indexAnimation::Downards)] = Animation(64, 64*10, 64, 64, 8, 0);
    animations[int(indexAnimation::Right)] = Animation(64, 64*11, 64, 64, 8, 0);
    // Idle Animation
    animations[int(indexAnimation::UpwardsIdle)] = Animation(0, 64*8, 64, 64, 1, 0);
    animations[int(indexAnimation::LeftIdle)] = Animation(0, 64*9, 64, 64, 1, 0);
    animations[int(indexAnimation::DownwardsIdle)] = Animation(0, 64*10, 64, 64, 1, 0);
    animations[int(indexAnimation::RightIdle)] = Animation(0, 64*11, 64, 64, 1, 0);
    
};

void Character::Draw(sf::RenderTarget& rt) const {
    rt.draw(sprite);
};

void Character::SetDirection(const sf::Vector2f& dir) {
    velocity = dir*speed;
    if (dir.x > 0.0f) {
        currentAnimation = indexAnimation::Right;
    } else if (dir.x < 0.0f) {
        currentAnimation = indexAnimation::Left;
    } else if (dir.y < 0.0f) {
        currentAnimation = indexAnimation::Upwards;
    } else if (dir.y > 0.0f) {
        currentAnimation = indexAnimation::Downards;
    } 
}

void Character::Update(float dt, float waitTime) {
    position += velocity*dt;

    // If no movement, switch to idle animation
    if (velocity.x == 0.0f && velocity.y == 0.0f) {
        switch (currentAnimation) {
            case indexAnimation::Right:
                currentAnimation = indexAnimation::RightIdle;
                break;
            case indexAnimation::Left:
                currentAnimation = indexAnimation::LeftIdle;
                break;
            case indexAnimation::Downards:
                currentAnimation = indexAnimation::DownwardsIdle;
                break;
            case indexAnimation::Upwards:
                currentAnimation = indexAnimation::UpwardsIdle;
                break;
            default:
                break;
        }
    }

    animations[int(currentAnimation)].Update(dt, waitTime);
    animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
    sprite.setPosition(position);
}