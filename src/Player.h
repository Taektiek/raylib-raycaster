#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        float playerX; // GRID COORDS
        float playerY;

        float playerAngle; // RADIANS

        Player(float x, float y);

        void movePlayer(float length);
        void rotatePlayer(float angle);

};

#endif