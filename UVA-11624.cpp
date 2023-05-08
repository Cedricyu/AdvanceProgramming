
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void pop_front(std::vector<T> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}
 
 
// void print_maze(int h,int w,char (*maze)[w]){
//     for (int i =0 ; i < h ; i++){
//         for(int j =0 ;j < w ;j++){
//             cout << maze[i][j];
//         }
//         cout << endl;
//     }
//     return;
// } 
int w,h;

bool in_range(int i,int j){
    return ( i < h && i >=0 )&&( j < w && j >=0 );
}



int main()
{
   int n;
   cin >> n;
   while(n){
        cin >> h >> w ;
       
        char maze[h][w];
        pair<int,int> player,fire;
        for (int i =0 ; i < h ; i++){
            for(int j =0 ;j < w ;j++){
                cin >> maze[i][j];
                if(maze[i][j]=='J')
                    player = make_pair(i,j);
                else if(maze[i][j]=='F')
                    fire = make_pair(i,j); 
            }
        }
        
        vector<pair<int ,int >> firequeue;
        vector<pair<int ,int >> playerqueue;
        
        firequeue.push_back(fire);
        playerqueue.push_back(player);
        int turn = 0;
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        bool break_the_loop = false;
        bool cannot_esacple = false;
        while(1){
            turn++;
            int firequeuecnt = firequeue.size();
            int playerqueuecnt = playerqueue.size();
            if(playerqueuecnt==0){
                break_the_loop = true;
                cannot_esacple = true;
            }
            for(int i=0 ; i<max(firequeuecnt,playerqueuecnt) ; i++){
                /// fire
                if(i < firequeuecnt){
                    pair<int,int> firepos = firequeue.front();
                    for(int j = 0 ; j < 4; j++){
                        pair<int,int> firenewpos = make_pair(firepos.first+dir[j][0],firepos.second+dir[j][1]);
                        if(in_range(firenewpos.first,firenewpos.second) && maze[firenewpos.first][firenewpos.second]=='.'){
                            firequeue.push_back(firenewpos);
                            maze[firenewpos.first][firenewpos.second] = 'F';
                        }
                    }
                    pop_front(firequeue);
                }
                /// end fire

                /// player
                if(i < playerqueuecnt){
                    pair<int,int> playerpos = playerqueue.front();
                    for(int j = 0 ; j < 4; j++){
                        pair<int,int> playernewpos = make_pair(playerpos.first+dir[j][0],playerpos.second+dir[j][1]);
                        if(!in_range(playernewpos.first,playernewpos.second))
                            break_the_loop = true;
                        else if(maze[playernewpos.first][playernewpos.second]=='.'){
                            playerqueue.push_back(playernewpos);
                            maze[playernewpos.first][playernewpos.second] = 'P';
                        }
                    }
                    pop_front(playerqueue);
                }
                /// end player
            }

            if(break_the_loop)
                break;
            
            /// print maze    
                // cerr << endl;
                // for (int i =0 ; i < h ; i++){
                //     for(int j =0 ;j < w ;j++){
                //         cerr << maze[i][j];
                //     }
                //     cerr << endl;
                // }
            /// end print maze
        }/// end find path
        if(cannot_esacple)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << turn << endl;
       n--;
       
   }// end  loop

    return 0;
}
