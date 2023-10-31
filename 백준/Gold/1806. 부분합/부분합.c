#include <stdio.h>
#include <stdlib.h>
int n,s,arr[100001];
int sum,l,r;
int min = 987654321;
int main()
{
    scanf("%d %d",&n,&s);
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    l = 0;
    r = 0;
    sum = arr[0];
    while(l <= r && r < n) {
        if(sum >= s) {
            min = min > r-l+1?r-l+1:min;
            sum -= arr[l++];
        }
        else if(sum < s) {
            sum += arr[++r];
        }
    }
    if(min == 987654321) printf("0");
    else printf("%d",min);
    return 0;
}
