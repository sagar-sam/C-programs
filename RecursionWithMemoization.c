#include <stdio.h>
#include <stdlib.h>
int f[51];
int fib(n)
{
    if(n<=1)
    {
        return n;
    }
    if(f[n]!=-1)
        return f[n];
    f[n]=fib(n-1)+fib(n-2);
    return f[n];
}
int main()
{
    int i,n;
    for(i=0;i<51;i++)
        f[i]=-1;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int x=fib(n);
    printf("%d\n",x);
    return 0;
}

//this is much much better in terms of time
