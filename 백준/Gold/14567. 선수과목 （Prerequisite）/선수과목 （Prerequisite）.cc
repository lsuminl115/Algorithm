#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
int tail[1001];
int answer[1001];
vector<int> v[1001];
void topo() {
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(!tail[i]) q.push(i);
    }
    int cnt = 1;
    while(!q.empty()) {
        int k = q.size();
        for(int i=0; i<k; i++) {
            int x = q.front();
            answer[x] = cnt;
            q.pop();

            int t = v[x].size();
            for(int i=0; i<t; i++) {
                if(!--tail[v[x][i]]) {
                    q.push(v[x][i]);
                }
            }
        }
        cnt++;
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        tail[b]++;
    }
    topo();
    for(int i=1; i<=n; i++) printf("%d ",answer[i]);
    return 0;
}
