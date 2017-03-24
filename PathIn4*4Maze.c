//To find path in a 4*4 maze
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left,*right,*up,*down;
    int index;
};

struct node s[16];
int findpath(int a,int b)
{
    if(s[a].index==b)
    {
        return 1;
    }
        if(s[a].down!=NULL&&findpath(a+4,b))
            return 1;
        if(s[a].right!=NULL&&findpath(a+1,b))
            return 1;
        if(s[a].left!=NULL&&findpath(a-1,b))
            return 1;
        if(s[a].up!=NULL&&findpath(a-4,b))
            return 1;
        return 0;
}
int main()
{
    int i;
    for(i=0;i<16;i++)
    {
        s[i].index=i;
        s[i].down=NULL;
        s[i].left=NULL;
        s[i].right=NULL;
        s[i].up=NULL;
        if(i==0||i==5||i==6||i==8||i==12||i==13||i==14)
               s[i].right=&s[i+1];
        if(i==1||i==4||i==5||i==6||i==8||i==9||i==10)
            s[i].down=&s[i+4];
        if(i==5)
            s[i].left=&s[i-1];
    }
    int a,b;
    printf("Enter the source and the destination\n");
    scanf("%d%d",&a,&b);
    int ans;
    ans=findpath(a,b);
    if(ans==1)
        printf("path found\n");
    else
        printf("path not found\n");

    return 0;
}
