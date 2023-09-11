#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;
typedef struct
{
    int index;
    int num;
}st;
vector<int> v[501];
queue<st> q;
int i,n,a,b,arr[501],backtail[501],x,num,dp[501],j,y,maxnum[501];
void topology()
{
    for(i=1;i<=n;i++)
    {
        if(!backtail[i]) q.push({i,0});
    }

    for(i=1;i<=n;i++)
    {
        x = q.front().index;
        num = q.front().num;
        num+=arr[x];

        dp[x] = num;

        q.pop();
        for(j=0;j<v[x].size();j++)
        {
            y = v[x][j];
            if(!--backtail[y])
            {
                if(maxnum[y] < num) q.push({y,num});
                else q.push({y,maxnum[y]});
            }
            else
            {
                if(maxnum[y] < num) maxnum[y] = num;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        arr[i] = a;
        while(1)
        {
            scanf("%d",&b);
            if(b==-1) break;
            v[b].push_back(i);
            backtail[i]++;
        }
    }

    topology();

    for(i=1;i<=n;i++)printf("%d\n",dp[i]);
    return 0;
}
