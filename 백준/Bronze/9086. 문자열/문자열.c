#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    char arr[1001];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%s",&arr);
        printf("%c%c\n",arr[0],arr[strlen(arr)-1]);
    }
    return 0;
}
