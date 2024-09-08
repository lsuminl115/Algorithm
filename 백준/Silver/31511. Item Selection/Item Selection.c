#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int checkbox;
    int want;
}st;
st item[1001];
int page[1001];
int n,m,s,p,q,pp,qq;
int sum;
int isOk(int start, int end) {
    for(int i=start; i<=end; i++) {
        if(item[i].checkbox == 0 && item[i].want == 0) {
            continue;
        }
        else if(item[i].checkbox == 0 && item[i].want == 1) {
            return 0;
        }
        else if(item[i].checkbox == 1 && item[i].want == 0) {
            return 0;
        }
        else {
            continue;
        }
    }
    return 1;
}
int find_checkbox(int start, int end) {
    int cnt = 0;
    for(int i=start; i<=end; i++) {
        if(item[i].checkbox == 0 && item[i].want == 0) {
            continue;
        }
        else if(item[i].checkbox == 0 && item[i].want == 1) {
            cnt++;
        }
        else if(item[i].checkbox == 1 && item[i].want == 0) {
            cnt++;
        }
        else {
            continue;
        }
    }
    return cnt;
}
int find_allselect(int start, int end) {
    int cnt = 1;
    for(int i=start; i<=end; i++) {
        if(item[i].want == 0) cnt++;
    }
    return cnt;
}
int find_disallselect(int start, int end) {
    int cnt = 1;
    for(int i=start; i<=end; i++) {
        if(item[i].want == 1) cnt++;
    }
    return cnt;
}
int main()
{
    scanf("%d %d %d %d %d",&n,&m,&s,&p,&q);
    for(int i=0; i<p; i++) {
        scanf("%d",&pp);
        item[pp].checkbox = 1;
    }
    for(int i=0; i<q; i++) {
        scanf("%d",&qq);
        item[qq].want = 1;
    }
    int pages = ceil((float)n / (float)m);
    for(int i=1; i<=pages; i++) {
        int start = (i-1) * m + 1;
        // int end = i * m;
        int end = (i == pages) ? n : i * m;

        // printf("start : %d end : %d\n",start, end);
        int min = 987654321;

        if(isOk(start, end)) {
            page[i] = 1;
            // printf("this Page is no touch\n");
            continue;
        }

        int tmp = find_checkbox(start, end);
        min = min > tmp ? tmp : min;

        tmp = find_allselect(start, end);
        min = min > tmp ? tmp : min;

        tmp = find_disallselect(start, end);
        min = min > tmp ? tmp : min;
        sum += min;
        // printf("this Page : %d, min value : %d\n",i, min);
    }
    // for(int i=1; i<=pages; i++) printf("%d ",page[i]);
    // puts("");

    int cnt_i = 0;
    int cnt_j = 0;
    for(int j=s-1; j>=1; j--) {
        if(page[j] == 0) {
            cnt_i += cnt_j + 1;
            cnt_j = 0;
        }
        else {
            cnt_j++;
        }
    }
    int left = cnt_i;

    cnt_i = 0;
    cnt_j = 0;
    for(int j=s+1; j<=pages; j++) {
        if(page[j] == 0) {
            cnt_i += cnt_j + 1;
            cnt_j = 0;
        }
        else {
            cnt_j++;
        }
    }
    int right = cnt_i;
    // printf("left : %d, right : %d\n", left, right);
    if(left > right) {
        int tmp = left;
        left = right;
        right = tmp;
    }

    printf("%d",(left*2+right) + sum);
    return 0;
}
