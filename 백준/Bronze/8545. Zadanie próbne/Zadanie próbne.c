#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[4];
    gets(arr);
    printf("%c%c%c",arr[2],arr[1],arr[0]);
    return 0;
}
