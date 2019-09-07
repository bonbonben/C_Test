#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3
#define swap(a,b) {a^=b; b^=a; a^=b;}
//宣告BOOL型態
typedef int BOOL;
//
typedef struct
{
    int x;
    int y;
} position;

//地圖
char map[10][10];

//函數宣告
BOOL walk(position *, int );
void print_map();
void shuffle_box(int *box);

int main(int argc, char *argv[])
{
    //打亂亂數種子
    srand((unsigned)time(NULL));
    //將地圖初始化為'.'
    memset(map,'.',10*10);

    //方向BOX
    int box[]= {UP,LEFT,DOWN,RIGHT};

    //初始化結構
    position cur_pos= {.x=0, .y=0};
    map[0][0]='A';  //第一步
    char step;
    for(step='B'; step<='Z'; step++)
    {
        //打亂方向BOX
        shuffle_box(box);
        //開始按box順序檢查四周，直到找到出路
        int i;
        for(i=0; i<4; i++)
            if(walk(&cur_pos,box[i])) break;
        //沒有路就不玩了><
        if(i==4) break;
        //凡走過必留痕跡
        map[cur_pos.y][cur_pos.x]=step;
    }
    //印出map
    print_map();

    return EXIT_SUCCESS;
}

BOOL walk(position *curpos, int movement)
{
    BOOL rnt=0;
    switch(movement)
    {
    case LEFT:
        rnt=(curpos->x-1>=0&&map[curpos->y][curpos->x-1]=='.');
        if(!rnt)
            rnt=2*(curpos->x-2>=0&&map[curpos->y][curpos->x-2]=='.');
        curpos->x-=rnt;
        break;
    case UP:
        rnt=(curpos->y-1>=0&&map[curpos->y-1][curpos->x]=='.');
        if(!rnt)
            rnt=2*(curpos->y-2>=0&&map[curpos->y-2][curpos->x]=='.');
        curpos->y-=rnt;
        break;
    case RIGHT:
        rnt=(curpos->x+1<10&&map[curpos->y][curpos->x+1]=='.');
        if(!rnt)
            rnt=2*(curpos->x+2<10&&map[curpos->y][curpos->x+2]=='.');
        curpos->x+=rnt;
        break;
    case DOWN:
        rnt=(curpos->y+1<10&&map[curpos->y+1][curpos->x]=='.');
        if(!rnt)
            rnt=2*(curpos->y+2<10&&map[curpos->y+2][curpos->x]=='.');
        curpos->y+=rnt;
        break;
    }
    return rnt;
}

void print_map()
{
    int i;

    for(i=0; i<100; i++)
    {
        printf("%c ", map[0][i]);
        putchar(i%10==9 ? '\n': '\0');
    }
}


void shuffle_box(int *box)
{
    int i;
    for(i=0; i<10; i++)
    {
        int f=rand()%4;
        int s=rand()%4;
        if(f!=s) swap(box[f],box[s]);
    }
}
