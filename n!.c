#include<stdio.h>
int function(int n);
int main()
{
    int a;
    int n;
    printf("enter number:");
    scanf("%d",&n);
    a=function(n);
    printf("answer=%d",a);
    return 0;
}

int function(int n)
{
    if(n==1)
        return 1;
    else
        return function(n-1)*n;
}
