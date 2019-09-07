#include <stdio.h>

int max(int A[], int n){
    int result=A[0];
    int i;
    for(i=0;i<n;i++)
        result=A[i]>result?A[i]:result;

    return result;
}

int main(int argc, char *argv[])
{
    int n;

    if(argc==1){
        fprintf(stderr, "Usage: max <num1> <num2> ..");
    }

    n=argc-1;

    int A[n];

    int i;
    for(i=0;i<n;i++){
        A[i]=atoi(argv[i+1]);
    }

    printf("%d", max(A,n));
}
