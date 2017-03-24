#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *p,*q;
    p=fopen("hello.txt","r");
    q=fopen("newfile.txt","a");
    if(p==NULL||q==NULL)
        printf("file not able to opened ");
    else
    {
        while(!feof(p))
        {
            char ch[30];
            fgets(ch,30,p);
            fputs(ch,q);
        }
    }
    return 0;
}
