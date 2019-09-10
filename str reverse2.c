#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,m;
    char a[10000];
    char b[10000];
    char c[3]="end";
    scanf("%s",a);
    n=strlen(a);
    m=strcmp(c,a);
    if(m==0)
    return 0;
    for(i=0,j=n-1;i<n;i++,j--)
        b[i]=a[j];
    b[n]='\0';/*結束用保險起見*/
    printf("%s",b);
    printf("\n");
    return 0;
}
