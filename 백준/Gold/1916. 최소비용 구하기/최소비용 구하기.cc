#include <bits/stdc++.h>
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
int INF = 987654321;
int dis[1001];
vector<node> v[1001];
void f(int start)
{
    priority_queue<node, vector<node>, compare> pq;
    pq.push({start,0});
    while(!pq.empty())
    {
        node x = pq.top();
        int current = x.next;
        int cur_dis = x.dis;
        pq.pop();
        if(dis[current] < cur_dis) continue;

        int t = v[current].size();
        for(int i=0; i<t; i++)
        {
            int next = v[current][i].next;
            int next_dis = cur_dis + v[current][i].dis;

            if(dis[next] > next_dis)
            {
                pq.push({next, next_dis});
                dis[next] = next_dis;
            }
        }
    }

}

int main()
{
    int n,m,a,b,c,s,e;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1; i<=n; i++) dis[i] = INF;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back({b,c});
    }
    scanf("%d %d",&s,&e);
    f(s);
    printf("%d",dis[e]);
    return 0;
}
