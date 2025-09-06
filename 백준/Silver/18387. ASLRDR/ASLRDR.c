#include <stdio.h>
#include <string.h>
int main() {
    int n;
    char arr[102];
    for(scanf("%d",&n);n--;) {
        int sum = 0;
        int flag = 0;
        scanf("%s", arr);
        int t = strlen(arr);
        for(int i=0; i<t/2; i++) {
            if(arr[i] == arr[t-i-1]) continue;

            int left = 0;
            int right = t-i-1;

            for(int j=i; j<t-i; j++) {
                if(arr[i] == arr[j]) left = j;
            }

            for(int j=t-i-1; j>=i; j--) {
                if(arr[t-i-1] == arr[j]) right = j;
            }

            // printf("%s\n", arr);
            
            int left_cost = (t-i-1) - (left);
            int right_cost = (right) - i;
            
            // printf("left : %c %d %d, right : %c %d %d\n\n", arr[i], left, left_cost, arr[t-i-1], right, right_cost);
            if(left == i) left_cost = 987654321;
            if(right == t-i-1) right_cost = 987654321;

            if((left == i) && (right == t-i-1)) {
                flag = 1;
            }

            if(left_cost <= right_cost) {
                sum += left_cost;
                for(int j=left; j<t-i-1; j++) {
                    char t = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = t;
                }
            }
            else {
                sum += right_cost;
                for(int j=right; j>i; j--) {
                    char t = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = t;
                }
            }
        }
        if(flag) printf("Impossible\n");
        else printf("%d\n", sum);
    }
    return 0;
}