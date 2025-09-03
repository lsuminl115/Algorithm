#include <bits/stdc++.h>
using namespace std;
int n, num, arr[300001];
int main() {
    scanf("%d", &n);

    if(n == 0) {
        printf("0");
        return 0;
    }

    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    num = (int) round(n * 0.15);
    sort(arr, arr+n);
    int sum = 0;
    int cnt = 0;
    for(int i=num; i<n-num; i++) {
        cnt++;
        sum += arr[i];
    }
    printf("%d", (int)round((double)sum / cnt));
    return 0;
}