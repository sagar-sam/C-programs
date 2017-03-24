#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,n,j;
    printf("Enter number of testcases: ");
    scanf("%d",&t);
    int *sum=(int*)malloc(t*sizeof(int));
    for(i=0;i<t;i++)
    {
        sum[i]=0;
	printf("Enter number: ");
        scanf("%d",&n);
        for(j=1;j<n;j++)
        {
            if(j%3==0)
                sum[i]+=j;s
            if(j%5==0)
                sum[i]+=j;
            if(j%15==0)
                sum[i]-=j;
        }
    }
    for(i=0;i<t;i++)
        printf("%d\n",sum[i]);
    return 0;
}
