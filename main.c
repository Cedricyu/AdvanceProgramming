
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# define Stacksize 1000000
//char maze[100][100];
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
struct stack{
    int top;
    char elements[Stacksize];
    //char dir[Stacksize];
};
typedef struct stack Stack;
void init_stack(Stack *s){
    s->top = 0;
}

bool stackfull(Stack *s){
    return (s->top >= Stacksize);
}

bool stackempty(Stack *s){
    return (s->top <=0 );
}

void pushStack(Stack *s, char i){
    if (stackfull(s)){
        //printf("stack is full\n");
        return ;
    }
    s->elements[s->top] = i;
    s->top++;
}

char popStack(Stack *s){
    s->top--;
    return (s->elements[s->top]);
}
void print_stack(Stack *s){
    for (int i=0;i<s->top;i++)
        printf("stack %c\n",s->elements[i]);
    printf("\n");
    return;
}
bool check(int x, int y, int len, int wid){
    //printf("x = %d y = %d\n",x,y);
    if ( x<0 || x >= wid )
        return false;
    if ( y<0 || y >= len )
        return false;
    //printf("maze = %c\n", maze[x][y]);
    return true;
}
/*
bool can_move(Stack *s , char c, int len, int wid, char maze[len+1][wid+1],int cur_x, int cur_y,int direction){
    if (c =='f'){
        int nex_x = cur_x + dir[direction][0];
        int nex_y = cur_y + dir[direction][1];
        //printf("maze = %c\n", maze[nex_x][nex_y]);
        //printf("x = %d y = %d\n",nex_x,nex_y);
        if(check(nex_x, nex_y, len, wid,maze)){
            return true;
        }}
    else if (c=='b'){
        int nex_x = cur_x - dir[direction][0];
        int nex_y = cur_y - dir[direction][1];
       // printf("maze = %c\n", maze[nex_x][nex_y]);
        //printf("x = %d y = %d\n",nex_x,nex_y);
        if(check(nex_x, nex_y, len, wid, maze)){
            return true;
        }}
    return false;
}*/
Stack copy_stack(Stack *s){
    Stack n;
    n.top = s->top;
    for (int i=0;i<s->top;i++)
        n.elements[i] = s->elements[i];
    return n;
}
int main(){
    
    int len=0,wid=0;
    scanf("%d %d", &len ,&wid);
    char maze[len+1][wid+1];
    
    for (int i=0; i<len; i++)
        scanf("%s", maze[i]);
    struct stack move;
    init_stack(&move);
    char actions[20];
    
    //Stack tmp;
    int direction =0;
    //int cur_x=0,cur_y=0;
    while (scanf("%s", actions)!=EOF){
        int cur_x=0,cur_y=0;
        int n = move.top;
        direction = 0;
        for (int i=0; i<n ; i++){
            char k = move.elements[i];
            if (k =='f'){
                cur_x += dir[direction][0];
                cur_y += dir[direction][1];
            }
                //pushStack(move,'f');
            else if (k=='b'){
                cur_x -= dir[direction][0];
                cur_y -= dir[direction][1];
            }
                //pushStack(move,'b');
            else if (k=='l'){
                direction --;
                if (direction < 0)
                    direction +=4;
            }
                //pushStack(move,'r');
            else if (k=='r'){
                direction ++;
                direction = direction % 4;
            }}
        if (strcmp(actions, "walk-forward")==0){
            int nex_x = cur_x + dir[direction][0];
            int nex_y = cur_y + dir[direction][1];
            //printf("maze = %c\n", maze[nex_x][nex_y]);
            //printf("x = %d y = %d\n",nex_x,nex_y);
            if(check(nex_x, nex_y, len, wid)){
                if (maze[nex_y][nex_x]!='#')
                    pushStack(&move,'f');
            }}
        else if (strcmp(actions, "walk-backward")==0){
            int nex_x = cur_x - dir[direction][0];
            int nex_y = cur_y - dir[direction][1];
           // printf("maze = %c\n", maze[nex_x][nex_y]);
            //printf("x = %d y = %d\n",nex_x,nex_y);
            if(check(nex_x, nex_y, len, wid)){
                if (maze[nex_y][nex_x]!='#')
                    pushStack(&move,'b');
            }}
        else if (strcmp(actions, "turn-right")==0)
            pushStack(&move,'r');
        else if (strcmp(actions, "turn-left")==0)
            pushStack(&move,'l');
        else if (strcmp(actions, "undo")==0){
            if ( n>0)
                popStack(&move);
        }
        //print_stack(&move);
        else if (strcmp(actions, "docchi")==0){
            printf("%d %d\n",cur_x,cur_y);
        }
        //free(&tmp);
    }
    return 0;
}
