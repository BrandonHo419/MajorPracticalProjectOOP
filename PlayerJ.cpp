#include "PlayerJ.h"

Player::Player() {
    money = 1000;
}

void Player::setMoney(float cost) {
    money = money - cost;
}
        
float Player::getMoney() {
    return money;
}

// all of this is irrelevant