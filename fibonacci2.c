#include<stdio.h>
int fibonacci(int n);

int main()
{
    int n;
    printf("enter number\n");
    scanf("%d",&n);
    int a=fibonacci(n);
    printf("answer=%d",a);
    return 0;
}

int fibonacci(int n)
{
    if (n<=1)
        return n;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}
