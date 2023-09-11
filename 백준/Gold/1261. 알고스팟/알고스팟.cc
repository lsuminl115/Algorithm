#include <bits/stdc++.h>
#define INF 54321
using namespace std;
typedef struct
{
    int x;
    int y;
    int cnt;
}st;
struct compare{
    bool operator()(st a, st b)
    {
        return a.cnt>b.cnt;
    }

};
priority_queue<st,vector<st>,compare> pq;
int n,m,cnt[101][101],check[101][101];
char arr[101][101];
void f()
{
    int x,y,k;
    while(!pq.empty())
    {
        x = pq.top().x;
        y = pq.top().y;
        k = pq.top().cnt;

        pq.pop();
        if(x<1||x>m||y<1||y>n) continue;

        if(arr[x][y]=='1') k++;

        if(cnt[x][y]>=k)
        {
            cnt[x][y] = k;

            if(check[x][y]) continue;

            check[x][y] = 1;
            pq.push({x-1,y,k});
            pq.push({x+1,y,k});
            pq.push({x,y-1,k});
            pq.push({x,y+1,k});

        }
    }
}
int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf(" %c",&arr[i][j]);
            cnt[i][j] = INF;
        }
    }
    pq.push({1,1,0});
    f();
    printf("%d",cnt[m][n]);
    return 0;
}
