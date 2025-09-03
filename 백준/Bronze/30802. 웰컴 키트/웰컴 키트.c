#include <stdio.h>
int n, size[7], sum, t, p;
int main() {
    scanf("%d", &n);
    for(int i=0; i<6; i++) {
        scanf("%d", &size[i]);
    }
    scanf("%d %d", &t, &p);

    for(int i=0; i<6; i++) {
        if(size[i] == 0) continue;
        sum += (size[i] - 1) / t + 1;
    }
    printf("%d\n", sum);
    printf("%d %d", n/p, n%p);
    return 0;
}