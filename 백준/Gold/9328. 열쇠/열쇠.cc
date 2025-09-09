#include <bits/stdc++.h>
using namespace std;
int t,n,m;
char arr[101][101];
char keys[27];
vector<char> key;
int docs;
int check[101][101];
void open_door() {
    int key_size = key.size();

    for(int k=0; k<key_size; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(key[k] == arr[i][j] + 32) arr[i][j] = '.';
            }
        }
    }
    key.clear();
}

void dfs(int i, int j) {
    if(check[i][j]) return;
    if(i < 0 || i >= n || j < 0 || j >= m) return;
    if('A' <= arr[i][j] && arr[i][j] <= 'Z') return;
    if(arr[i][j] == '*') return;

    // printf("%d %d\n", i, j);
    if('a' <= arr[i][j] && arr[i][j] <= 'z') {
        key.push_back(arr[i][j]);
        // printf("find key %c\n", arr[i][j]);
        arr[i][j] = '.';
    } 
    if(arr[i][j] == '$') {
        docs++;
        arr[i][j] = '.';
    }

    check[i][j] = 1;
    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}
int main() {
    for(scanf("%d", &t);t--;) {
        scanf("%d %d ", &n, &m);
        docs = 0;
        for(int i=0; i<n; i++) scanf("%s", arr[i]);
        scanf("%s", keys);
        int key_size = strlen(keys);
        for(int i=0; i<key_size; i++) {
            if(keys[i] == '0') break;
            key.push_back(keys[i]);
        }
        while(1) {
            
            // puts("============ open before =========\n");
            // for(int i=0; i<n; i++,puts(""))for(int j=0; j<m; j++)printf("%c",arr[i][j]);
            
            open_door();
            
            // puts("============ open after =========\n");
            // for(int i=0; i<n; i++,puts(""))for(int j=0; j<m; j++)printf("%c",arr[i][j]);


            // 외곽 돌면서 빈곳에서 dfs 시작
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if((1 <= i && i <= (n-2)) && (1 <= j && j <= (m-2))) continue;
                    if(arr[i][j] == '.' || arr[i][j] == '$') dfs(i, j);
                    else if('a' <= arr[i][j] && arr[i][j] <= 'z') dfs(i, j);
                }
            }

            for(int i=0;i<n;i++)for(int j=0;j<m;j++) check[i][j] = 0;

            if(key.size() == 0) {
                printf("%d\n", docs);
                break;
            }


        }
    }
    return 0;
}