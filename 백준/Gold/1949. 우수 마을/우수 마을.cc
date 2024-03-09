#include <bits/stdc++.h>
using namespace std;
vector<int> v[10001];
int n,a,b;
int dp[10001][2];
int value[10001];
void dfs(int node, int parent) {

    dp[node][0] = 0;
    dp[node][1] = value[node];

    int t = v[node].size();

    for(int i=0; i<t; i++) {
        int k = v[node][i];
        if(k == parent) continue;
        dfs(k, node);
        dp[node][0] += dp[k][0] < dp[k][1] ? dp[k][1] : dp[k][0];
        dp[node][1] += dp[k][0];
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&value[i]);
    for(int i=0; i<n-1; i++) {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, -1);
    printf("%d",dp[1][0] < dp[1][1] ? dp[1][1] : dp[1][0]);
    return 0;
}
