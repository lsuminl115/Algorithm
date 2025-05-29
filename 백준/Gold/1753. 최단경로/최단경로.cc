#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int current;
    int distance;
}st;
struct compare {
    bool operator()(st a, st b) {
        return a.distance > b.distance;
    }
};
int dis[20001];
vector<st> arr[20001];

void dijkstra(int start) {
    dis[start] = 0;
    priority_queue<st, vector<st>, compare> pq;
    pq.push({start, 0});

    while(!pq.empty()) {
        int current = pq.top().current;
        int distance = pq.top().distance;

        pq.pop();

        if(dis[current] < distance) continue;

        for(int i=0; i<arr[current].size(); i++) {
            int next = arr[current][i].current;
            int next_distance = distance + arr[current][i].distance;
            if(next_distance < dis[next]) {
                dis[next] = next_distance;
                pq.push({next, next_distance});
            }
        }
    }
}
int main() {

    int vertex, edge, start, u, v, w;
    scanf("%d %d",&vertex,&edge);
    scanf("%d",&start);

    for(int i=1; i<=vertex; i++) dis[i] = 987654321;

    for(int i=0; i<edge; i++) {
        scanf("%d %d %d",&u, &v, &w);
        arr[u].push_back({v, w});
    }
    dijkstra(start);
    for(int i=1; i<=vertex; i++) {
        if(dis[i] == 987654321) printf("INF\n");
        else printf("%d\n", dis[i]);
    }
    return 0;
}