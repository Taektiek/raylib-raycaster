#ifndef GRID_H
#define GRID_H
#include <vector>

class Grid {
    public:
        int width;
        int height;

        int cellSize = 40;

        std::vector<int> gridMatrix;

        Grid(int width, int height);

        int getMatrixItem(int x, int y);
        void setMatrixItem(int x, int y, int a);

        void printMatrix();
};

#endif