#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int index;
    int value;
}st;
struct compare {
    bool operator()(st a, st b) {
        return a.value > b.value;
    }
};
priority_queue<st, vector<st>, compare> pq;
int arr[5000001];
int main()
{
    int n,l;
//    scanf("%d %d",&n,&l);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;

    //for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int i=1; i<=n; i++) {
        pq.push({i, arr[i]});
        if(i > l) {
            while(pq.top().index < i-l+1) pq.pop();
        }
        //printf("%d ",pq.top().value);
        cout << pq.top().value << " ";
    }
    return 0;
}
