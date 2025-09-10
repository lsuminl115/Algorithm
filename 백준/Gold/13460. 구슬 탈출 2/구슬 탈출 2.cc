#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int x,y;
}st;
int n,m; 
int min_k = 999;
char arr[11][11];
// return : wall or ball -> 0 / hole -> 1
int forward(st& ball, st& ball2, int d, char c) {
    // left
    if(d == 1) {
        while(1) {
            if(arr[ball.x][ball.y-1] == '#') return 0;
            if(ball.x == ball2.x && ball.y-1 == ball2.y) return 0;
            if(arr[ball.x][ball.y-1] == 'O') {
                ball.x = 0;
                ball.y = 0;
                return 1;
            }
            ball.y--;
        }
    }
    
    // right
    else if(d == 2) {
        while(1) {
            if(arr[ball.x][ball.y+1] == '#') return 0;
            if(ball.x == ball2.x && ball.y+1 == ball2.y) return 0;
            if(arr[ball.x][ball.y+1] == 'O') {
                ball.x = 0;
                ball.y = 0;
                return 1;
            }
            ball.y++;
        }
    }

    // up
    else if(d == 3) {
        while(1) {
            if(arr[ball.x-1][ball.y] == '#') return 0;
            if(ball.x-1 == ball2.x && ball.y == ball2.y) return 0;
            if(arr[ball.x-1][ball.y] == 'O') {
                ball.x = 0;
                ball.y = 0;
                return 1;
            }
            ball.x--;
        }
    }

    // down
    else {
        while(1) {
            if(arr[ball.x+1][ball.y] == '#') return 0;
            if(ball.x+1 == ball2.x && ball.y == ball2.y) return 0;
            if(arr[ball.x+1][ball.y] == 'O') {
                ball.x = 0;
                ball.y = 0;
                return 1;
            }
            ball.x++;
        }
    }
}
int f(st blue, st red, int k) {
    if(k == 10) {
        return 999;
    }

    // printf("blue : %d %d, red : %d %d, k : %d, min_k : %d\n", blue.x, blue.y, red.x, red.y, k, min_k);

    k++;
    st new_blue, new_red;
    int r = 0;
    int b = 0;
    int left, right, up, down;
    // left
    new_blue = blue;
    new_red = red;
    if(red.y <= blue.y) {
        if(forward(new_red, new_blue, 1, 'R')) r++;
        if(forward(new_blue, new_red, 1, 'B')) b++;

        if(r == 1) {
            if(b == 1) left = 999;
            else left = k;
        }
        else if(b == 1) left = 999;
        else left = f(new_blue, new_red, k);

        min_k = min_k > left ? left : min_k;
    }
    else {
        if(forward(new_blue, new_red, 1, 'B')) b++;
        if(forward(new_red, new_blue, 1, 'R')) r++;
                if(r == 1) {
            if(b == 1) left = 999;
            else left = k;
        }
        else if(b == 1) left = 999;
        else left = f(new_blue, new_red, k);
        min_k = min_k > left ? left : min_k;
    }
    // right
    new_blue = blue;
    new_red = red;
    r = b = 0;
    if(red.y >= blue.y) {
        if(forward(new_red, new_blue, 2, 'R')) r++;
        if(forward(new_blue, new_red, 2, 'B')) b++;


        if(r == 1) {
            if(b == 1) right = 999;
            else right = k;
        }
        else if(b == 1) right = 999;
        else right = f(new_blue, new_red, k);
        min_k = min_k > right ? right : min_k;
    }
    else {
        if(forward(new_blue, new_red, 2, 'B')) b++;
        if(forward(new_red, new_blue, 2, 'R')) r++;
        if(r == 1) {
            if(b == 1) right = 999;
            else right = k;
        }
        else if(b == 1) right = 999;
        else right = f(new_blue, new_red, k);
        min_k = min_k > right ? right : min_k;
    }

    // up
    new_blue = blue;
    new_red = red;
    r = b = 0;
    if(red.x <= blue.x) {
        if(forward(new_red, new_blue, 3, 'R')) r++;
        if(forward(new_blue, new_red, 3, 'B')) b++;
        if(r == 1) {
            if(b == 1) up = 999;
            else up = k;
        }
        else if(b == 1) up = 999;
        else up = f(new_blue, new_red, k);
        min_k = min_k > up ? up : min_k;
    }
    else {
        if(forward(new_blue, new_red, 3, 'B')) b++;
        if(forward(new_red, new_blue, 3, 'R')) r++;
        if(r == 1) {
            if(b == 1) up = 999;
            else up = k;
        }
        else if(b == 1) up = 999;
        else up = f(new_blue, new_red, k);
        min_k = min_k > up ? up : min_k;
    }

    // down
    new_blue = blue;
    new_red = red;
    r = b = 0;
    if(red.x >= blue.x) {
        if(forward(new_red, new_blue, 4, 'R')) r++;
        if(forward(new_blue, new_red, 4, 'B')) b++;
        if(r == 1) {
            if(b == 1) down = 999;
            else down = k;
        }
        else if(b == 1) down = 999;
        else down = f(new_blue, new_red, k);
        min_k = min_k > down ? down : min_k;
    }
    else {
        if(forward(new_blue, new_red, 4, 'B')) b++;
        if(forward(new_red, new_blue, 4, 'R')) r++;
        if(r == 1) {
            if(b == 1) down = 999;
            else down = k;
        }
        else if(b == 1) down = 999;
        else down = f(new_blue, new_red, k);
        min_k = min_k > down ? down : min_k;
    }

    return min_k;
    
}

int main() {
    st blue, red;
    scanf("%d %d ", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%s", arr[i]);
    }

    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        if(arr[i][j] == 'B') {
            blue.x = i;
            blue.y = j;
            arr[i][j] = '.';
        }
        if(arr[i][j] == 'R') {
            red.x = i;
            red.y = j;
            arr[i][j] = '.';
        }
    }
    int answer = f(blue, red, 0);
    if(answer > 10) printf("-1");
    else printf("%d", answer);
    return 0;
}