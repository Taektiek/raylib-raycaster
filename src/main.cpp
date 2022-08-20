#include "raylib.h"
#include <math.h>
#include <iostream>

#include "Grid.h"
#include "Player.h"


int main(void)
{

    Grid castGrid = Grid(11, 5);
    Player player = Player(1, 1);

    player.playerAngle = 0;

    for (int i = 0; i < 10; i++) {
        castGrid.setMatrixItem(i, 0, 1);
        castGrid.setMatrixItem(0, i, 1);
        castGrid.setMatrixItem(i, castGrid.height-1, 1);
        castGrid.setMatrixItem(castGrid.width-1, i, 1);
        castGrid.setMatrixItem(i, i, 1);
        castGrid.setMatrixItem(castGrid.width-i-1, i, 1);
    }

    castGrid.printMatrix();

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib raycast");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_RIGHT)) player.rotatePlayer(0.1);
        if (IsKeyDown(KEY_LEFT)) player.rotatePlayer(-0.1);
        if (IsKeyDown(KEY_UP)) player.movePlayer(0.1);
        if (IsKeyDown(KEY_DOWN)) player.movePlayer(-0.1);

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("grid?", 10, 10, 20, DARKGRAY);
            
            int cs = castGrid.cellSize; // CELL SIZE
            int cm = 50; // CELL MARGIN

            for (int x = 0; x < castGrid.width; x++) {
                for (int y = 0; y < castGrid.height; y++) {
                    if (castGrid.getMatrixItem(x, y) == 1) {
                        DrawRectangle(x*cs+cm, y*cs+cm, cs, cs, MAROON);
                    }
                }
            }

            float px = player.playerX+0.5;
            float py = player.playerY+0.5;
            float pa = player.playerAngle;

            DrawCircleV({(int)(cm+px*cs), (int)(cm+py*cs)}, 15, YELLOW);
            DrawLine((int)(cm+px*cs), (int)(cm+py*cs), (int)(cm+(px+cos(pa))*cs), (int)(cm+(py+sin(pa))*cs), BLUE);

        EndDrawing();
    }

    CloseWindow();  

    return 0;
}