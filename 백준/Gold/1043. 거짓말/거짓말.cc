#include <stdio.h>
#include <stdlib.h>
int node[51];
int arr[51][51];
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
int isEq(int a, int b) {
    a = get(a);
    b = get(b);

    if(a == b) return 1;
    return 0;
}
int isOk(int index, int t) {
    for(int i=0; i<t; i++) {
        if(get(arr[index][i+1]) == 0) return 0;
    }
    return 1;
}
int main()
{
    int n,m,k,know;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++) node[i] = i;
    scanf("%d",&k);
    for(int i=0; i<k; i++) {
        scanf("%d",&know);
        node[know] = 0;
    }
    for(int i=0; i<m; i++) {
        scanf("%d", &arr[i][0]);
        for(int j=0; j<arr[i][0]; j++) {
            scanf("%d",&arr[i][j+1]);
        }
    }
    for(int k=0; k<m; k++) {
        for(int i=0; i<m; i++) {
            if(!isOk(i, arr[i][0])) {
                for(int j=0; j<arr[i][0]; j++) uni(arr[i][j+1], 0);
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<m; i++) {
        if(isOk(i, arr[i][0])) cnt++;
    }
    printf("%d",cnt);
    return 0;
}
