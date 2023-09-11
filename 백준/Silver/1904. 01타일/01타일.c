#include <stdio.h>
#include <stdlib.h>
#define D 15746
int n, arr[1000001]={1,1};
int main()
{
    scanf("%d",&n);
    for(int i=2; i<=n; i++)
    {
        arr[i] = (arr[i-1] % D + arr[i-2] % D) % D;
    }
    printf("%d",arr[n]);
    return 0;
}
