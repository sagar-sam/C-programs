#include <stdio.h>
#include <stdlib.h>
int add(int a,int b)
{
    return a+b;
}

void printhello(char* name)
{
    printf("hello %s \n",name);
}
int main()
{
    int c;
    int (*p)(int,int);
    p=&add;//or p=add
    c=(*p)(2,3);//or c=p(2,3)
    printf("%d\n",c);
    void (*ptr)(char*);//pointer deffinition
    ptr=printhello;//pointer assigning
    ptr("tom");//function calling from pointer
    return 0;
}
