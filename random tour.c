#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    char square[10][10];
    int row,col,direction;
    char x ='B';
    int flag ;
    for(row=0;row<10;row++)
        for(col=0;col<10;col++)
            square[row][col]='.';
    square[0][0]='A';
    srand(time(NULL));
    row =0;
    col =0;
    for(;x<='Z';x++){
        flag=1;
        while(flag==1)
        {
            direction=(rand()%100)+1;
            direction=direction%4;
            if((square[row-1][col]!='.'||row-1<0)&&(square[row+1][col]!='.'||row+1>9)&&(square[row][col-1]!='.'||col-1<0)&&(square[row][col+1]!='.'||col+1>9))
            {
                flag=0;
                x='Z'+1;
                break;
            }
            switch (direction)
            {
                case 0:if(row-1<0||square[row-1][col]!='.'){flag=1;}else{row--;flag=0;}break;
                case 1:if(row+1>9||square[row+1][col]!='.'){flag=1;}else{row++;flag=0;}break;
                case 2:if(col-1<0||square[row][col-1]!='.'){flag=1;}else{col--;flag=0;}break;
                case 3:if(col+1>9||square[row][col+1]!='.'){flag=1;}else{col++;flag=0;}break;
            }
        }
        if (x<='Z')square[row][col]=x;
    }

    for(row=0;row<10;row++)
    for(col=0;col<10;col++)
    {
        printf("%2c",square[row][col]);
        if(col==9)
            printf("\n");
    }
    return 0;
}
