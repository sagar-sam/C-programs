#include <stdio.h>
#include <stdlib.h>

void tower(int num,char frompeg,char topeg,char auxpeg)
{
    if(num==1)
    {
        printf("move disc 1 from peg %c to %c\n",frompeg,topeg);
        return;
    }
    tower(num-1,frompeg,auxpeg,topeg);
    printf("move dsic %d from peg %c to peg %c\n",num,frompeg,topeg);
    tower(num-1,auxpeg,topeg,frompeg);
}

int main()
{
    int num;
    printf("Enter numer of discs: ");
    scanf("%d",&num);
    printf("The solution is\n");
    tower(num,'a','b','c');
    return 0;
}
