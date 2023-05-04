#include <iostream>

#include "robot.h"


using namespace std;

int main() {
    int w, h;
    int n;
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
            loop = i - test.Read_Step(x,y);
            dis = test.Read_Step(x,y);
            break;
        }
        Player.move(test,i);
        cnt++;
    }
    
    if(loop!=0)
        n = (n-dis)%loop;
    Player.start(test);

    for (int i = 0; i < n + dis ; i++) {
        Player.next_move(test);
        Player.move(test,i);
    }
    cout << Player.get_x() << " " << Player.get_y() << endl;
    return 0;
}
