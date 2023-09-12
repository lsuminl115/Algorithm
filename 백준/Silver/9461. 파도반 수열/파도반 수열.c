#include <stdio.h>
#include <stdlib.h>
long long int arr[200];
long long int f(long long int n)
{
    if(arr[n] != 0) return arr[n];

    if(n<=3) return 1;
    else if(n==4 || n==5) return 2;
    else
    {
        arr[n] = f(n-1) + f(n-5);
        return arr[n];
    }
}


int main()
{
    int n,i,a;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        printf("%lld\n",f(a));
    }
    return 0;
}
