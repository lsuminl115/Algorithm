#include <bits/stdc++.h>
using namespace std;
int n,m,k,a,cnt;
int job[1001];
bool check[1001];

vector<int> v[1001];

bool dfs(int x) {
    int t = v[x].size();
    for(int i=0; i<t; i++) {
        int y = v[x][i];
        if(check[y]) continue;
        check[y] = true;

        if(job[y] == 0 || dfs(job[y])) {
            job[y] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++){
        scanf("%d",&k);
        for(int j=0; j<k; j++) {
            scanf("%d",&a);
            v[i].push_back(a);
        }
    }
    for(int i=1; i<=n; i++) {
        fill(check, check+1001, false);
        if(dfs(i)) cnt++;
    }
    printf("%d",cnt);
    return 0;
}
