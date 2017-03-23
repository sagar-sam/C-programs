#include <stdio.h>
#include <stdlib.h>
#define macro(a,b) (a*a-b*b)

int main(int argc,char* argv[])
{
    int n,i,j,temp;
    
    n=atoi(argv[1]);
    int *ptr=(int*)malloc(2*n*sizeof(int));
    printf("Enter n pair of items:\n");
    for(i=0;i<2*n;i=i+2){
        scanf("%d",&ptr[i]);
        scanf("%d",&ptr[i+1]);
    }
    for(i=0;i<2*n;i=i+2){
        for(j=i;j<2*n;j=j+2){
            if(macro(ptr[i],ptr[i+1])>macro(ptr[j],ptr[j+1])){
                temp=ptr[i];
                ptr[i]=ptr[j];
                ptr[j]=temp;
                temp=ptr[i+1];
                ptr[i+1]=ptr[j+1];
                ptr[j+1]=temp;
            }
        }
        printf("%d  ",ptr[i]);
        printf("%d\n",ptr[i+1]);
    }
    return 0;
}
