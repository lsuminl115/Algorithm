#include <stdio.h>
#include <stdlib.h>
int n;
int arr[46];
int main()
{
    scanf("%d",&n);
    arr[1] = 1;
    for(int i=2; i<=n; i++) arr[i] = arr[i-1] + arr[i-2];
    printf("%d",arr[n]);
    return 0;
}
