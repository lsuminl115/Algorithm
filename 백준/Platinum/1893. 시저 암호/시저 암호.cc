#include <bits/stdc++.h>

using namespace std;

vector<int> make_table(char str[]) {
    int str_size = strlen(str);
    vector<int> table(str_size, 0);
    int j = 0;

    for(int i=1; i<str_size; i++) {
        while(j > 0 && str[i] != str[j]) j = table[j-1];
        if(str[i] == str[j]) table[i] = ++j;
    }
    return table;
}

int kmp(char code[], char str[]) {
    vector<int> table = make_table(str);
    int code_len = strlen(code);
    int str_len = strlen(str);
    int j = 0;
    int cnt = 0;

    for(int i=0; i<code_len; i++) {
        while(j > 0 && code[i] != str[j]) j = table[j-1];
        if(code[i] == str[j]) {
            if(j == str_len - 1) {
                cnt++;
            j = table[j];
            }
            else j++;
        }
    }
    return cnt;
}

int t;
char order[64];
char original[50001];
char code[500001];
int original_order[50001];
int main()
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for(scanf("%d",&t);t--;) {
        scanf("%s", &order);
        scanf("%s", &original);
        scanf("%s", &code);

        int original_len = strlen(original);
        int order_len = strlen(order);
        for(int i=0; i<original_len; i++) {
            for(int j=0; j<order_len; j++) {
                if(original[i] == order[j]) {
                    original_order[i] = j;
                    break;
                }
            }
        }
        for(int i=0; i<order_len; i++) {
            for(int j=0; j<original_len; j++) {
                original[j] = order[(original_order[j] + i) % order_len];
            }
            int k = kmp(code, original);
            if(k == 1) pq.push(i);
        }
        if(pq.empty()) {
            printf("no solution\n");
        }
        else {
            if(pq.size() == 1) {
                printf("unique: %d\n",pq.top());
            }
            else {
                printf("ambiguous: ");
                while(!pq.empty()) {
                    printf("%d ", pq.top());
                    pq.pop();
                }
                printf("\n");
            }
        }
        while(!pq.empty()) pq.pop();
    }
    return 0;
}
