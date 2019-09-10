#include <stdio.h>
#include <stdlib.h>
unsigned long long int power(unsigned long long int a,unsigned long long int m,unsigned long long int n);
int main(int argc,char *argv[])
{
    unsigned long long int a=strtoull(argv[1],NULL,10);
    unsigned long long int m=strtoull(argv[2],NULL,10);
    unsigned long long int n=strtoull(argv[3],NULL,10);
    unsigned long long int result;
    result=power(a,m,n);
    printf("%llu",result);
    return 0;
}
unsigned long long int power(unsigned long long int a,unsigned long long int m,unsigned long long int n)
{
    if(m==1)
    {
        return a%n;
    }
    if(m%2==1)
        return ((power(a,m-1,n)%n)*(power(a,1,n)%n))%n;
    return ((power(a,m/2,n)%n)*(power(a,m/2,n)%n))%n;
}
