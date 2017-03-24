#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count=0;
    FILE *p;
    p=fopen("sagar.txt","r");
    if(p==NULL)
        printf("error opening file");
    else
    {
        while(!feof(p))
        {
            char ch=fgetc(p);
            if(ch=='\n')
                count++;
        }
        printf("the number of lines are %d\n",count);
    }
    return 0;
}
