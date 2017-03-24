#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("poiter to poiter\n");
    int x=5;
    int *p;
    p=&x;
    int **q;
    q=&p;
    int ***r;
    r=&q;
    printf("%d\n",p);
    printf("%d\n",*p);
    printf("%d\n",q);
    printf("%d\n",*q);
    printf("%d\n",**q);
    printf("%d\n",*r);
    printf("%d\n",**r);
    printf("%d\n",***r);
    return 0;
}
