#include "player.h"

Player::Player(int width) {
    //Player begins in the top middle of the map
    x = width / 2;
    y = 0;
}

int Player::getX() {
    return x;
}

int Player::getY() {
    return y;
}

void Player::setPos(int x, int y) {
    this->x = x;
    this->y = y;
}