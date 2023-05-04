#ifndef ROBOT_H
#define ROBOT_H

#include "maze.h"

class Robot{
    public:
        void start(const Maze test){
            for(int i =0; i < test.h ; i++){
                for (int j = 0; j < test.w; j++) {
                    if (test.grid[i][j] == 'O') {
                        this->cur_x = j;
                        this->cur_y = i;
                    }
                }
            } 
            dir =0;
        };
        void move(Maze &test,int stepcnt);
        int check_move(const Maze test, int direction);
        void next_move(const Maze test);
        inline int get_x()const{ return cur_x; }
        inline int get_y()const{ return cur_y; }
        inline int get_dir()const{ return dir; }
        bool Loop (const Maze test)const;

    private:
        int cur_x, cur_y;
        int start_x = -1, start_y = -1;
        int dir=0;
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {-1, 0, 1, 0};
};
#endif