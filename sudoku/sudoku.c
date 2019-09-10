#include<stdio.h>
#include<stdlib.h>

int check(int ,int A[][9],int ,int);

int main()
{
    FILE *fpr=fopen("answer.txt","w");
    FILE *fp=fopen("input.txt","r");
    int A[9][9],r[81],c[81];
    int row,col,k,num,a;
    int *p[81];
    k=0;
    for(row=0;row<9;row++)
        for(col=0;col<9;col++)
        {
            fscanf(fp,"%d",&A[row][col]);
            if(A[row][col]==0)
            {
                p[k]=&A[row][col];
                r[k]=row;
                c[k]=col;
                k++;
            }
        }
    row=0;
    while(row<k)
    {
        a=0;
        while(a==0)
        {
            *p[row]+=1;
            num=*p[row];
            a=check(num,A,r[row],c[row]);
        }
        if(*p[row]>9)
        {
            *p[row]=0;
            row--;
        }
        else
        {
            row++;
        }
    }
    for(row=0;row<9;row++)
    {
        for(col=0;col<9;col++)
        {
            fprintf(fpr,"%d ",A[row][col]);
        }
        fprintf(fpr,"\n");
    }
    fclose(fpr);
}

int check(int num,int A[][9],int row,int col)
{
    int i,j;
    for(j=0;j<9;j++)
    {
        if(j==col)continue;
        if(A[row][j]==num)return 0;
    }
    for(i=0;i<9;i++)
    {
        if(i==row)continue;
        if(A[i][col]==num)return 0;
    }
    if(row>-1&&row<3&&col>-1&&col<3)
    {
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            {
                if(i==row&&j==col)continue;
                if(A[i][j]==num)return 0;
            }
    }
    if(row>-1&&row<3&&col>2&&col<6)
    {
        for(i=0;i<3;i++)
            for(j=3;j<6;j++)
            {
                if(i==row&&j==col)continue;
                if(A[i][j]==num)return 0;
            }
    }
    if(row>-1&&row<3&&col>5&&col<9)
    {
        for(i=0;i<3;i++)
            for(j=6;j<9;j++)
            {
                if(i==row&&j==col)continue;
                if(A[i][j]==num)return 0;
            }
    }
    if(row>2&&row<6&&col>-1&&col<3)
    {
        for(i=3;i<6;i++)
            for(j=0;j<3;j++)
            {
                if(i==row&&j==col)continue;
                if(A[i][j]==num)return 0;
            }
    }
    if(row>2&&row<6&&col>2&&col<6)
    {
        for(i=3;i<6;i++)
            for(j=3;j<6;j++)
            {
                if(i==row&&j==col)continue;
                if(A[i][j]==num)return 0;
            }
    }
    if(row>2&&row<6&&col>5&&col<9)
    {
        for(i=3;i<6;i++)
            for(j=6;j<9;j++)
            {
                if(i==row&&j==col)continue;
                if(A[i][j]==num)return 0;
            }
    }
    if(row>5&&row<9&&col>-1&&col<3)
    {
        for(i=6;i<9;i++)
            for(j=0;j<3;j++)
            {
                if(i==row&&j==col)continue;
                if(A[i][j]==num)return 0;
            }
    }
    if(row>5&&row<9&&col>2&&col<6)
    {
        for(i=6;i<9;i++)
            for(j=3;j<6;j++)
            {
                if(i==row&&j==col)continue;
                if(A[i][j]==num)return 0;
            }
    }
    if(row>5&&row<9&&col>5&&col<9)
    {
        for(i=6;i<9;i++)
            for(j=6;j<9;j++)
            {
                if(i==row&&j==col)continue;
                if(A[i][j]==num)return 0;
            }
    }
    return 1;
}
