#include <stdio.h>
#include <stdlib.h>
int main()
{
    int e=2;
    int wh=6;
    int wl=6;
    int i,j,k,count,n;
    int x=1;

    for(i=0;i<wh;i++)
    {
        for(j=wh;j<=wh+i;j++)
        {
            printf(" ");
        }
        for(count=1;count<=wl;count++)
        {
            for(n=wh+wl-2;n>=x;n--)
            {
                printf(" ");
            }
            for(k=1;k<=e;k++)
            {
                if(k==1)
                    printf("/");
                else if(k==e)
                    printf("\\");
                else
                    printf(" ");
            }
        }
        x+=2;
        e+=2;
        printf("\n");
    }

    return 0;
}
