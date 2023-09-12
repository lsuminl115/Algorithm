#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[50] = {0,1,1},n;
    for(int i=3; i<50; i++) arr[i] = arr[i-1] + arr[i-2];
    scanf("%d",&n);
    printf("%d %d",arr[n-1],arr[n]);
    return 0;
}
