#include <bits/stdc++.h>
using namespace std;
long long sum, arr[100001];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%lld",&arr[i]);
    }
    sort(arr, arr+n);
    for(int i=0; i<n; i++) {
        int j = (i + 1) % n;
        sum += arr[i]<arr[j]?arr[j]:arr[i];
    }
    printf("%lld",sum);
    return 0;
}
