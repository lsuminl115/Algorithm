#include <bits/stdc++.h>
using namespace std;
vector<int> vec[1000001];
int dp[1000001];
int check[1000001];
int dfs(int node, int parent) {
    if(vec[node].size() == 0) {
        return 0;
    }
    int sum = 0;
    int t = vec[node].size();
    for(int i=0; i<t; i++) {
        if(vec[node][i] != parent) {
            sum += dfs(vec[node][i], node);
            if(check[vec[node][i]] == 0) check[node] = 1;
        }
    }
    if(check[node]) return dp[node] = sum + 1;
    return dp[node] = sum;
}
int main()
{
    int n,u,v;
    scanf("%d",&n);
    for(int i=0; i<n-1; i++) {
        scanf("%d %d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1, -1);
    printf("%d",dp[1]);
    return 0;
}
