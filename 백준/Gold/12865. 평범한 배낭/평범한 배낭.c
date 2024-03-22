#include <stdio.h>
#include <stdlib.h>
int w[101],v[101],dp[101][100001];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d",&w[i],&v[i]);
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(j < w[i]) dp[i][j] = dp[i-1][j];
            else
            {
                int a = dp[i-1][j];
                int b = dp[i-1][j-w[i]]+v[i];
                dp[i][j] = a<b?b:a;
            }
        }
    }
    printf("%d",dp[n][k]);
    return 0;
}
