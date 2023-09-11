#include <stdio.h>
#include <stdlib.h>
int arr[1001][1001],dp[1001][1001];
int main()
{
    int n,i,j,max = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    for(i=1;i<=n;i++)
    {
        if(i==1)
        {
            dp[1][1] = arr[1][1];
            continue;
        }
        for(j=1;j<=i;j++)
        {
            if(j==1) dp[i][j] = dp[i-1][j] + arr[i][j];
            else if(j==i) dp[i][j] = dp[i-1][j-1] + arr[i][j];
            else
            {
                if(dp[i-1][j-1] > dp[i-1][j]) dp[i][j] = dp[i-1][j-1] + arr[i][j];
                else dp[i][j] = dp[i-1][j] + arr[i][j];
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(max < dp[n][i]) max = dp[n][i];
    }
    printf("%d",max);
    return 0;
}
