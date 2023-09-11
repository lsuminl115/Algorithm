#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int work[1001],backtail[1001],t,n,k,a,b,w,x,y;
int dp[1001];
queue<int> q;
void topology(vector<int> *v)
{
    for(int i=1;i<=n;i++)
    {
        if(!backtail[i])
        {
            dp[i] = work[i];
            q.push(i);
        }
    }

    for(int i=1;i<=n;i++)
    {
        x = q.front();
        q.pop();

        for(int j=0;j<v[x].size();j++)
        {
            y = v[x][j];
            if(!--backtail[y])
            {
                dp[y] = max(dp[y],dp[x]) + work[y];
                q.push(y);
            }
            else
            {
                dp[y] = max(dp[y],dp[x]);
            }
        }
    }
}
int main()
{
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        vector<int> v[1001];
        scanf("%d %d",&n,&k);
        for(int j=1;j<=n;j++) scanf("%d",&work[j]);
        for(int j=1;j<=k;j++)
        {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            backtail[b]++;
        }
        scanf("%d",&w);

        topology(v);
        printf("%d\n",dp[w]);

        for(int j=1; j<=1001; j++) dp[j]=0;
    }
    return 0;
}
