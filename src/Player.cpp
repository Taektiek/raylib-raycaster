#include "Player.h"
#include <math.h>
#include <iostream>

Player::Player(float x, float y) {
    playerX = x;
    playerY = y;
}

void Player::movePlayer(float length) {
    playerX = playerX + cos(playerAngle) * length;
    playerY = playerY + sin(playerAngle) * length;
}

void Player::rotatePlayer(float angle) {
    playerAngle = fmod((playerAngle + angle), 4*acos(0.0));
}