#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[]={2,4,5,8,1},i;
    for(i=0;i<5;i++)
    {
        printf("address=%d\n",(a+i));
        printf("address=%d\n",&a[i]);
        printf("value=%d\n",a[i]);
        printf("value=%d\n",*(a+i));
    }
    int *p;
    p=a;  //or p=&a[0]
    //a++    invalid
    p++;  //valid
    printf("%d\n",p);
    return 0;
}
