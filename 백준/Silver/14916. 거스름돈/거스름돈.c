#include <stdio.h>
#include <stdlib.h>
int n;
int coin[2] = {2, 5};
int dp[100001];
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) dp[i] = 987654321;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<2; j++) {
            if((coin[j] <= i) && (dp[i] > dp[i-coin[j]] + 1)) dp[i] = dp[i-coin[j]] + 1;
        }
    }
    printf("%d",dp[n]==987654321?-1:dp[n]);
    return 0;
}
