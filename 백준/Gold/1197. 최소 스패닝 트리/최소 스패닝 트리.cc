#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int a;
    int b;
    int c;
}st;
struct compare {
    bool operator()(st a, st b) {
        return a.c > b.c;
    }
};
priority_queue<st, vector<st>, compare> pq;
int node[10001];
int get(int x) {
    if(x == node[x]) return x;
    return node[x] = get(node[x]);
}
void uni(int a, int b) {
    a = get(a);
    b = get(b);
    if(a < b) node[b] = a;
    else node[a] = b;
}
int isOk(int a, int b) {
    a = get(a);
    b = get(b);
    if(a == b) return 1;
    return 0;
}
int main()
{
    int v,e,a,b,c;
    scanf("%d %d",&v,&e);
    for(int i=1; i<=v; i++) node[i] = i;
    for(int i=0; i<e; i++) {
        scanf("%d %d %d",&a,&b,&c);
        pq.push({a, b, c});
    }
    int cnt = 0;
    int ans = 0;
    while(!pq.empty() && cnt < v-1) {
        st x = pq.top();
        pq.pop();
        if(!isOk(x.a, x.b)) {
            uni(x.a, x.b);
            ans += x.c;
            cnt++;
        }
    }
    printf("%d",ans);
    return 0;
}
