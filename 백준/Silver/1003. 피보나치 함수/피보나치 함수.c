#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,arr[41][2],i,a;
    scanf("%d",&n);
    arr[0][0] = 1;
    arr[0][1] = 0;
    arr[1][0] = 0;
    arr[1][1] = 1;
    for(i=2;i<=40;i++)
    {
        arr[i][0] = arr[i-1][0] + arr[i-2][0];
        arr[i][1] = arr[i-1][1] + arr[i-2][1];
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        printf("%d %d\n",arr[a][0],arr[a][1]);
    }
    return 0;
}
