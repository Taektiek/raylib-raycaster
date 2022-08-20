#include "Raycaster.h"

#include <math.h>

std::vector<float> cast(Grid castGrid, float x, float y, float angle, float stepSize, int stepLimit) {
    float casterX = x;
    float casterY = y;

    for (int i = 0; i < stepLimit; i++) {
        casterX = casterX + cos(angle)*stepSize;
        casterY = casterY + sin(angle)*stepSize;

        if (castGrid.getMatrixItem((int) casterX, (int) casterY) == 1) {
            return {casterX, casterY};
        }
    }
    return {0, 0};
}

float calculateDistance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}