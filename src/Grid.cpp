#include "Grid.h"
#include <iostream>

Grid::Grid(int w, int h) {
    width = w;
    height = h;

    for (int i=0; i<width*height; i++) {
        gridMatrix.push_back(0);
    }

    std::cout << width << " " << height << std::endl;
}

int Grid::getMatrixItem(int x, int y) {
    return gridMatrix[y*width+x%width];
}

void Grid::setMatrixItem(int x, int y, int a) {
    gridMatrix[y*width+x%width] = a;
}

void Grid::printMatrix() {
    for (int i = 0; i < width * height; i ++) {
        std::cout << gridMatrix[i] << " ";
        if (i % (width ) == width-1) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}