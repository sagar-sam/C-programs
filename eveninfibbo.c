#include <stdio.h>
#include <stdlib.h>
int fibbonacci(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fibbonacci(n-1)+fibbonacci(n-2);
}

int main()
{
    int i,t,n;
    printf("Enter number of test cases:\n");
    scanf("%d",&t);
    int *sum=(int*)malloc(t*sizeof(int));
    for(i=0;i<t;i++)
    {
        sum[i]=0;
        int num=0,m=0;
        printf("Enter number: ");
        scanf("%d",&n);
        while(m<=n)
        {
            m=fibbonacci(num);
            if(m%2==0)
                sum[i]+=m;
            num++;
        }
    }
    for(i=0;i<t;i++)
        printf("%d\n",sum[i]);
    return 0;
}
