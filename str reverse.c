#include<stdio.h>
#include<string.h>

int main(void)
{
    char input[1000];
    char reverse[1000];
    int length;
    int i;

    while(scanf("%s",input)!=EOF)
    {
        if(strcmp(input,"end")==0 || strcmp(input,"END")==0)
        {
            printf("end program\n");
            break;
        }
        else
        {
            length=strlen(input);

            for(i=length-1;i>=0;i--)
            {

                reverse[length-i]=input[i];
            }
            reverse[length+1]='\0';

            printf("Reverse of input %s is %s\n",input,reverse);
        }
    }
}
