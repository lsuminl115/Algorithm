#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef struct {
    int next;
    int dis;
}node;

struct compare {
    bool operator()(node a, node b)
    {
        if(a.dis > b.dis) return 1;
        return 0;
    }
};
int arr[801],n;
vector<node> v[801];
void f(int start)
{
    priority_queue<node, vector<node>, compare> pq;
    pq.push({start, 0});

    while(!pq.empty())
    {
        node p = pq.top();
        pq.pop();

        int current = p.next;
        int dis = p.dis;

        if(arr[current] < dis) continue;
        int t = v[current].size();
        for(int i=0; i<t; i++)
        {
            int next = v[current][i].next;
            int next_dis = v[current][i].dis + dis;
            if(arr[next] > next_dis)
            {
                arr[next] = next_dis;
                pq.push({next, next_dis});
            }
        }
    }
}
int s(int x, int next)
{
    int sum = 0;
    for(int i=1; i<=n; i++) arr[i] = INF;
    f(x);
    if(arr[next] == INF) return -10000000;
    return arr[next];
}
int main()
{
    int e,a,b,c,u,w,sum;
    scanf("%d %d",&n,&e);
    for(int i=0; i<e; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    scanf("%d %d",&u,&w);
    if(u==1)
    {
        if(w==n)
        {
            sum = s(1, n);
        }
        else sum = s(1, w) + s(w, n);
    }
    else
    {
        if(w==n) sum = s(1, u) + s(u, n);
        else
        {
            sum = s(1, u) + s(u, w) + s(w, n);
            if(s(1, w) + s(w, u) + s(u, n) < sum) sum = s(1, w) + s(w, u) + s(u, n);
        }
    }
    printf("%d",sum<0?-1:sum);
    return 0;
}
