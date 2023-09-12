#include <stdio.h>
#include <stdlib.h>
int a[500001];
int num_arr[1000001];
long long int tree[2000004];
long long int search(int left, int right, int node, int start, int end)
{
    /*
    if(left == value) return tree[node];
    if(right == value) return 0;

    int mid = (left + right) / 2;
    if(mid > value) return search(left, mid, node * 2, value) + tree[node * 2 + 1];
    if(mid < value) search(mid + 1, right, node * 2 + 1, value);
    if(left == right) return 0;
    return tree[node * 2 + 1];
    */
    if(end < left || right < start) return 0;
    if(start <= left && right <= end) return tree[node];

    int mid = (left + right) / 2;
    return search(left, mid, node * 2, start, end) + search(mid + 1, right, node * 2 + 1, start, end);


}
long long int update(int left, int right, int node, int index)
{
    if(index < left || right < index) return tree[node];
    if(left == right) return tree[node] = 1;
    int mid = (left + right) / 2;
    return tree[node] = update(left, mid, node * 2, index) + update(mid + 1, right, node * 2 + 1, index);
}
int main()
{
    int n,b;
    long long int sum = 0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&b);
        num_arr[b] = i;
    }

    for(int i=1; i<=n; i++)
    {
        b = num_arr[a[i]];
        sum += search(1,n,1,b,n);
        update(1,n,1,b);
    }
    printf("%lld",sum);

    return 0;
}
