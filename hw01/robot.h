#include <iostream>
#include "maze.h"

class Robot{
    public:
        void start(const Maze test){
            //int start_x = -1, start_y = -1;
            //cout << "test "<< test.w << test.h << endl ;
            for(int i =0; i < test.h ; i++){
                for (int j = 0; j < test.w; j++) {
                    //cout << test.grid[i][j];
                    if (test.grid[i][j] == 'O') {
                        this->cur_x = j;
                        this->cur_y = i;
                    }
                }
                //cout << endl;
            } 
            dir =0;
            //cout << "start x y" << cur_x << cur_y << endl;
        };
        void move(Maze &test,int stepcnt);
        int check_move(const Maze test, int direction);
        void next_move(const Maze test);
        inline int get_x(){ return cur_x; }
        inline int get_y(){ return cur_y; }
        inline int get_dir(){ return dir; }
        bool Loop(const Maze test);

    private:
        int cur_x, cur_y;
        int start_x = -1, start_y = -1;
        int dir=0;
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {-1, 0, 1, 0};
};