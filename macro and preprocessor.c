#include <stdio.h>
#include <stdlib.h>
#define india 1
#define us 2
#define pak 3
#define COUNTRY india
#define any "print this "
int main()
{
    printf("code for whole of the world\n");
    printf(any);
    #if COUNTRY==india
    printf("code for indians\n");
    #elif COUNTRY==us
    printf("code for us\n");
    #elif COUNTRY==PAK
    printf("code for pakistan\n");
    #else
    printf("code for the rest of the world\n");
    #endif // country
    return 0;
}
