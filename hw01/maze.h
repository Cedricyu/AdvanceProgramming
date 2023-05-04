
#ifndef MAZE_H
#define MAZE_H
#include <iostream>
const int MAX_W  = 20;
const int MAX_H  = 10;

class Maze{
    friend class Robot;
    private:
        int w,h;
        char grid[MAX_H][MAX_W];
        int map[MAX_H][MAX_W];
        int step[MAX_H][MAX_W];
    public:
        Maze(int width, int height){
            w = width;
            h = height;
            for(int i = 0; i < h; i++) {
                for(int j = 0; j < w; j++) {
                    this->map[i][j] = -1;
                    this->step[i][j] = 0;
                    std::cin >> grid[i][j];
                }
            }
        }
        void check()const;
        char Read_Grid(const int x,const int y)const{return grid[y][x];}
        int Read_Step(const int x,const int y)const{return step[y][x];}
        int Read_Map(const int x,const int y)const{return map[y][x];}
};
#endif