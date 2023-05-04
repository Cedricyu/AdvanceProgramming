#include "maze.h"

void Maze::check()const{
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            std::cout << step[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
}