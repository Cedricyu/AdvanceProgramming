#include <iostream>
#include <vector>
#include "robot.h"


using namespace std;

int main() {
    int w, h;
    unsigned long long n;
    cin >> w >> h >> n;

    Maze test(w,h);

    Robot Player;

    Player.start(test);

    int cnt =0;
    int dis =0;
    int loop =0;
    
    for (int i = 0; i < n; i++) {
        
        const int x = Player.get_x(), y = Player.get_y();
        Player.next_move(test);
        if(Player.Loop(test)){
            //cout << "find loop" << endl;
            loop = i - test.Read_Step(x,y);
            dis = test.Read_Step(x,y);
            break;
        }
        Player.move(test,i);
        //test.check();
        //cout << "x y ="<< Player.get_x() << " " << Player.get_y() << endl;
        cnt++;
    }
    //test.check();
    //cout << "loop =" << loop << " dis =" << dis << "cnt =" << cnt << endl;
    if(loop!=0)
        n = (n-dis)%loop;
    Player.start(test);

    for (int i = 0; i < n + dis ; i++) {
        const int x = Player.get_x(), y = Player.get_y();
        Player.next_move(test);
        Player.move(test,i);
    }
    //test.check();
    // print the final position of the robot
    cout << Player.get_x() << " " << Player.get_y() << endl;

    return 0;
}
