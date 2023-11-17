#include <bits/stdc++.h>
#define INF 123456789
using namespace std;
typedef struct {
    int node;
    int dis;
}st;
struct compare {
    bool operator()(st a, st b)
    {
        return a.dis > b.dis;
    }
};
vector<st> vec[20001];
int dis[20001];
void f(int start)
{
    priority_queue<st, vector<st>, compare> pq;
    dis[start] = 0;

    pq.push({start, 0});
    while(!pq.empty())
    {
        st a = pq.top();
        pq.pop();

        if(dis[a.node] < a.dis) continue;

        for(int i=0; i<vec[a.node].size(); i++)
        {
            st b = vec[a.node][i];
            if(dis[b.node] > a.dis + b.dis)
            {
                dis[b.node] = a.dis + b.dis;
                pq.push({b.node, a.dis + b.dis});
            }
        }
    }
}


int main()
{
    int v,e,k,a,b,c;
    scanf("%d %d",&v,&e);
    scanf("%d",&k);
    for(int i=1; i<=v; i++) dis[i] = INF;
    for(int i=0; i<e; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        vec[a].push_back({b, c});
    }
    f(k);

    for(int i=1; i<=v; i++,puts(""))
    {
        if(dis[i] == INF) printf("INF");
        else printf("%d",dis[i]);
    }
    return 0;
}
