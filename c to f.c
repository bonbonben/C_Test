#include<stdio.h>
float ctof(int c)
{
    return 9.00/5.00*c+32.00;
}

int main()
{
    float c,f;
    scanf("%f",&c);
    f=ctof(c);
    /*f=9.00/5.00*c+32.00;*/
    printf("c=%f\n",c);
    printf("9.00/5.00*c+32.00=%f\n",f);
    return 0;
}
