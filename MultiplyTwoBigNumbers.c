#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j;
    int a[100],b[100],c[100];
    char sa[100];
    printf("Enter first number: ");
    scanf("%s",sa);
    int n=strlen(sa);
    for(i=0;i<n;i++)
    {
        a[i]=sa[i]-'0';
    }
    printf("Enter second number: ");
    scanf("%s",sa);
    int m=strlen(sa);
    for(i=0;i<m;i++)
    {
        b[i]=sa[i]-'0';
    }
    for(i=0;i<100;i++)
        c[i]=0;
    int t=1;
    int carry=0;
    for(i=n-1;i>=0;i--)
    {
        carry=0;
        int x=n+m-t;
        for(j=m-1;j>=0;j--)
        {
            int temp=a[i]*b[j]+carry;
            int y=c[x]+temp%10;
            c[x]=y%10;
            int temp2=c[x-1]+y/10;
            c[x-1]=temp2%10;
            c[x-2]+=temp2/10;
            carry=temp/10;
            x--;
        }
        c[x]=carry;
        t++;
    }
    printf("The product is: ");
    for(i=0;i<n+m;i++)
        printf("%d",c[i]);
    printf("\n");
}
