#include <stdio.h>
#include <stdlib.h>
int check[20000001];
int arr[5001];
int num[5001];
int n,sum;
int f()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(arr[j])
            {
                if(check[sum + j])
                {
                    //printf("%d ",j);
                    sum += j;
                    arr[j] = 0;
                    num[i] = j;
                    break;
                }
            }
        }
    }
}
int main()
{
    check[0] = 1;
    check[1] = 1;
    for(int i=2; i*i<=20000000; i++)
    {
        if(!check[i])
        {
            for(int j=i+i; j<=20000000; j+=i) check[j] = 1;
        }
    }
    scanf("%d",&n);
    for(int i=1; i<=n; i++) arr[i]=1;
    f();
    int k;
    for(k=1; k<=n; k++)
    {
        if(!num[k]) break;
    }

    if(k != n+1) printf("NO");
    else
    {
        printf("YES\n");
        for(k=1; k<=n; k++) printf("%d ",num[k]);
    }
    return 0;
}
