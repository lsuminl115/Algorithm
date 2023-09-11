#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int dp[100001];
int main()
{
    int n,a,i,j,min=111111,b;
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        a = sqrt(i);
        min = 111111;
        for(j=a;j>=1;j--)
        {
            b = pow(j,2.0);
            if(min > dp[i-b]) min = dp[i-b];
        }
        dp[i] = min + 1;
    }
    printf("%d",dp[n]);
    return 0;
}
