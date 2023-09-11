#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int n,m,i,j,start,eend,backtail[10001],x,y,z,dp[10001],maxnum,a,b,c,X,Y,ttail[10001];
int cnt=0,k;
typedef struct
{
    int me;
    int next;
    int time;
}st;
queue<int> q;
vector<st> v[10001],vv[10001];
void topology()
{
    q.push(start);
    while(!q.empty())
    {
        k = q.size();
        for(i=1;i<=k;i++)
        {
            x = q.front();
            q.pop();
            for(j=0;j<v[x].size();j++)
            {
                y = v[x][j].next;
                z = v[x][j].time;
                if(!--backtail[y])
                {
                    q.push(y);
                    dp[y] = max(dp[y],dp[x]+z);
                }
                else
                {
                    dp[y] = max(dp[y],dp[x]+z);
                }
            }
        }
    }
}
void dps(int A)
{
    bool check[10001] = {};
    queue<int> qq;
    q.push(A);
    check[A] = true;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i=0; i<vv[x].size();i++)
        {
            int y = vv[x][i].next;
            int z = vv[x][i].time;

            if(check[x] && (dp[x] - z == dp[y]))
            {
                cnt++;
                check[y] = true;
            }
            if(!--ttail[y]) q.push(y);
        }
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%d",&m);

    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back({a,b,c});
        vv[b].push_back({b,a,c});
        backtail[b]++;
        ttail[a]++;
    }
    scanf("%d %d",&start,&eend);
    topology();
    dps(eend);
    printf("%d\n",dp[eend]);
    printf("%d",cnt);
    return 0;
}