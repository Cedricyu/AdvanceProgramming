#include "maze.h"

void Maze::check()const{
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << step[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}