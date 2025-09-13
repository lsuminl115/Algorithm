#include <stdio.h>
#define N 1000
typedef struct {
    long long int arr[6][6];
}st;
int n;
st f(st a, long long int m) {
    if(m == 1) return a;
    
    st x = f(a, m/2);
    if(m % 2 == 0) {
        st y = {{{0, }}};
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                for(int k=1; k<=n; k++) {
                    y.arr[i][j] = ((y.arr[i][j] % N) + ((x.arr[i][k] % N) * (x.arr[k][j] % N)) % N) % N;
                }
            }
        }
        return y;
    }
    else {
        st y = {{{0, }}};;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                for(int k=1; k<=n; k++) {
                    y.arr[i][j] = ((y.arr[i][j] % N) + ((x.arr[i][k] % N) * (x.arr[k][j] % N)) % N) % N;
                }
            }
        }
        st z = {{{0, }}};;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                for(int k=1; k<=n; k++) {
                    z.arr[i][j] = ((z.arr[i][j] % N) + ((y.arr[i][k] % N) * (a.arr[k][j] % N)) % N) % N;
                }
            }
        }
        return z;
    }
}
int main() {
    long long int m;
    st input;
    scanf("%d %lld", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%lld", &input.arr[i][j]);
        }
    }

    st answer = f(input, m);

    for(int i=1; i<=n; i++,puts("")) {
        for(int j=1; j<=n; j++) {
            printf("%lld ", answer.arr[i][j] % N);
        }
    }
    return 0;
}