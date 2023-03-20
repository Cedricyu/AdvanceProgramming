#include <iostream>
#define MAX_W 20
#define MAX_H 10
using namespace std;

class Maze{
    friend class Robot;
    private:
        int w,h;
        char grid[MAX_H][MAX_W];
        int map[MAX_H][MAX_W];
        int step[MAX_H][MAX_W];
    public:
        Maze(int width, int height){
            //grid.resize(h);
            w = width;
            h = height;
            for(int i = 0; i < h; i++) {
                for(int j = 0; j < w; j++) {
                    this->map[i][j] = -1;
                    this->step[i][j] = 0;
                    cin >> grid[i][j];
                }
            }
           //check();
        }
        void check()const;
        char Read_Grid(const int x,const int y)const{return grid[y][x];}
        int Read_Step(const int x,const int y)const{return step[y][x];}
        int Read_Map(const int x,const int y)const{return map[y][x];}
};