#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <vector>
typedef struct
{
    int next;
    int num;
}st;
vector<st> v[10001];
int max_sum=0;
void dfs(bool check[10001], int k,int sum)
{
    int x,y,t;
    check[k] = true;
    for(t=0;t<v[k].size();t++)
    {
        x = v[k][t].next;
        y = v[k][t].num;
        if(check[x] == true)
        {
            if(max_sum < sum)
            {
                max_sum = sum;
            }
            continue;
        }
        dfs(check,x,sum+y);
    }
}
int main()
{
    int n,i,a,b,c,j;
    bool check[10001];
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    for(i=1;i<=n;i++)
    {
        dfs(check,i,0);
        for(j=1;j<=10000;j++)check[j]=false;
    }

    printf("%d",max_sum);
    return 0;
}
