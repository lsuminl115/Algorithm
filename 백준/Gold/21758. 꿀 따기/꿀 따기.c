#include <stdio.h>
#include <stdlib.h>
int n,max,k;
int sum[100001];
int arr[100001];
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d",&arr[i]);
    }
    for(int i=1; i<=n; i++) {
        sum[i] = sum[i-1] + arr[i];
    }
    for(int i=2; i<=n; i++) {
        k = (sum[n] - sum[1] - arr[i]) + (sum[n] - sum[i]);
        max = max < k ? k : max;
    }
    for(int i=1; i<n; i++) {
        k = (sum[n-1] - arr[i]) + (sum[i] - arr[i]);
        max = max < k ? k : max;
    }
    for(int i=2; i<n; i++) {
        k = (sum[i] - arr[1]) + (sum[n] - arr[n] - sum[i-1]);
        max = max < k ? k : max;
    }
    printf("%d",max);
    return 0;
}
