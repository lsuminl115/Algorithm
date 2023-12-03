#include <stdio.h>
#include <stdlib.h>
int n;
int coin[2] = {2, 5};
int dp[100001];
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) dp[i] = 987654321;
    for(int i=0; i<2; i++) {
        for(int j=1; j<=n; j++) {
            if((coin[i] <= j) && (dp[j] > dp[j-coin[i]] + 1)) dp[j] = dp[j-coin[i]] + 1;
        }
    }
    printf("%d",dp[n]==987654321?-1:dp[n]);
    return 0;
}
