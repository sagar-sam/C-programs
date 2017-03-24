//peeling off algorithm

#include <stdio.h>
#include <stdlib.h>

void printspiral(int a[][4],int m,int n)
{
    int t=0,b=m-1,r=n-1,l=0;
    int i;
    int dir=0;/*dir tells us where we have to go 0 signifies right 1 means down 2 means left 3 means up*/
    while(t<=b&&l<=r)
    {
        if(dir==0)
        {
            for(i=l;i<=r;i++)
                printf("%d  ",a[t][i]);
            dir++;
            t+=1;
        }
        if(dir==1)
        {
            for(i=t;i<=b;i++)
                printf("%d  ",a[i][r]);
            dir++;
            r-=1;
        }
        if(dir==2)
        {
            for(i=r;i>=l;i--)
                printf("%d  ",a[b][i]);
            dir++;
            b-=1;
        }
        if(dir==3)
        {
            for(i=b;i>=t;i--)
                printf("%d  ",a[i][l]);
            dir=0;
            l+=1;
        }
    }
}



int main()
{
    int array[4][4]={{2,4,6,8},{5,9,12,16},{2,11,5,9},{3,2,1,8}};
    printspiral(array,4,4);
    printf("\n");
    return 0;
}
