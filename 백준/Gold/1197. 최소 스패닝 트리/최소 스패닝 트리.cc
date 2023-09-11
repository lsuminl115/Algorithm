#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int a;
    int b;
    int value;
}st;
struct compare {
    bool operator()(st a, st b)
    {
        return a.value > b.value;
    }
};
int cnt;
int parent[10001];

int get(int x)
{
    if(parent[x] == x) return x;
    else return parent[x] = get(parent[x]);
}
void uni(int a, int b)
{
    a = get(a);
    b = get(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}
int cmp(int a, int b)
{
    a = get(a);
    b = get(b);
    if(a == b) return 1;
    else return 0;
}
int main()
{
    priority_queue<st, vector<st>, compare> pq;
    int n,m,a,b,c;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++) parent[i] = i;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        pq.push({a,b,c});
    }

    while(!pq.empty())
    {
        st k = pq.top();
        pq.pop();
        if(!cmp(k.a, k.b))
        {
            cnt += k.value;
            uni(k.a, k.b);
        }
    }
    printf("%d",cnt);
    return 0;
}
