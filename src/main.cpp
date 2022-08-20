#include "raylib.h"
#include <math.h>
#include <iostream>
#include <vector>

#include "Grid.h"
#include "Player.h"
#include "Raycaster.h"


int main(void)
{

    Grid castGrid = Grid(20, 20);
    Player player = Player(3, 1);

    const bool drawGrid = false;

    float fov = 1.5 * acos(0.0);
    int horizontalRes = 400;

    player.playerAngle = 0;

    for (int i = 0; i < 20; i++) {
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

            float px = player.playerX+0.5;
            float py = player.playerY+0.5;
            float pa = player.playerAngle;
            
            if (drawGrid) {


                for (int x = 0; x < castGrid.width; x++) {
                    for (int y = 0; y < castGrid.height; y++) {
                        if (castGrid.getMatrixItem(x, y) == 1) {
                            DrawRectangle(x*cs+cm, y*cs+cm, cs, cs, MAROON);
                        }
                    }
                }


                DrawCircleV({(int)(cm+px*cs), (int)(cm+py*cs)}, 15, YELLOW);

                for (float i = -1; i < 1; i += 0.01) {
                    std::vector<float> castCoords = cast(castGrid, px, py, player.playerAngle + i, 0.01, 1000);
                    DrawLine((int)(cm+px*cs), (int)(cm+py*cs), (int)(cm+castCoords[0]*cs), (int)(cm+castCoords[1]*cs), GREEN);
                }

                DrawLine((int)(cm+px*cs), (int)(cm+py*cs), (int)(cm+(px+cos(pa))*cs), (int)(cm+(py+sin(pa))*cs), BLUE);

            }

            for (int i = 0; i < horizontalRes; i++) {
                float angleOffset = ((float) i / horizontalRes) * fov - 0.5 * fov;
                std::vector<float> castCoords = cast(castGrid, px, py, pa + angleOffset, 0.01, 1000);
                int screenRectXCoord = screenWidth/horizontalRes * i;
                float castDistance = calculateDistance(player.playerX, player.playerY, castCoords[0], castCoords[1]);
                int rectHeight = (int)(1/(castDistance)*400);
                DrawRectangle(screenRectXCoord, screenHeight/2-rectHeight/2, screenWidth/horizontalRes, rectHeight, MAROON);
            }


        EndDrawing();
    }

    CloseWindow();  

    return 0;
}