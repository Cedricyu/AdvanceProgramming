#include <iostream>
#include "robot.h"

int Robot::check_move(const Maze test,const int direction){
    
    int nx = cur_x + dx[direction], ny = cur_y + dy[direction];
    if (test.grid[ny][nx] != '#') {
        return direction;
    }
    return check_move(test,(direction + 1) % 4);
}

void Robot::next_move(const Maze test){
    dir = check_move(test,dir);
}

bool Robot::Loop(const Maze test)const{
    return (test.Read_Map(cur_x,cur_y) == dir);
}
void Robot::move(Maze &test ,const int stepcnt){
    test.map[cur_y][cur_x] = dir;
    test.step[cur_y][cur_x] = stepcnt;
    int nx = cur_x + dx[dir], ny = cur_y + dy[dir];
    cur_x = nx;
    cur_y = ny;
    return;
}
