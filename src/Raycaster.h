#ifndef RAYCASTER_H
#define RAYCASTER_H

#include "Grid.h"
#include <vector>

std::vector<float> cast(Grid castGrid, float x, float y, float angle, float stepSize, int stepLimit);
float calculateDistance(float x1, float y1, float x2, float x3);

#endif