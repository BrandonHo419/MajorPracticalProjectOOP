#include "Player.h"
#include <iomanip>
#include <sstream>

Player::Player(const sf::Vector2f& position): position(position), money(80.f) {
    // Walking animations
    animations[int(indexAnimation::Upwards)] = Animation(64, 64*8, 64, 64, 8, 1);
    animations[int(indexAnimation::Left)] = Animation(64, 64*9, 64, 64, 8, 1);
    animations[int(indexAnimation::Downards)] = Animation(64, 64*10, 64, 64, 8, 1);
    animations[int(indexAnimation::Right)] = Animation(64, 64*11, 64, 64, 8, 1);
    // Idle Animation
    animations[int(indexAnimation::UpwardsIdle)] = Animation(0, 64*8, 64, 64, 1, 1);
    animations[int(indexAnimation::LeftIdle)] = Animation(0, 64*9, 64, 64, 1, 1);
    animations[int(indexAnimation::DownwardsIdle)] = Animation(0, 64*10, 64, 64, 1, 1);
    animations[int(indexAnimation::RightIdle)] = Animation(0, 64*11, 64, 64, 1, 1);
    
    // Parameters are (x, y, width, height, number of frames, animationID)
};

void Player::Draw(sf::RenderTarget& rt) const {
    rt.draw(sprite);
};

void Player::SetDirection(const sf::Vector2f& dir) {
    // If movement, apply animation
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

void Player::Update(float dt, float waitTime, bool resetFrame) {
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

    // Applies the animation
    animations[int(currentAnimation)].Update(dt, waitTime, resetFrame, 0);
    animations[int(currentAnimation)].ApplyAnimToSprite(sprite);
    sprite.setScale(sf::Vector2f(3, 3));
    sprite.setPosition(position);
}

sf::Vector2f Player::getCharPosition() {
    return position;
}

void Player::setCharPosition(float x, float y) {
    sprite.setPosition(x, y);
    position = {x, y};
}

void Player::setMoney(float cost) {
    money = money - cost;
}

void Player::addMoney(float revenue) {
    money = money + revenue;
}

float Player::getMoney() {
    return money;
}

std::string Player::getMoneyStr() {
    std::ostringstream playerStream;
    playerStream << std::fixed << std::setprecision(2) << money; // Format to two decimal places
    std::string moneyString = playerStream.str(); // Get the formatted string
    return moneyString;
}