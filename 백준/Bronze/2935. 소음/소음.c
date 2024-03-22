#include <stdio.h>
#include <stdlib.h>
char a[101],b[101];
char k;
int main()
{
    scanf("%s",&a);
    scanf("%s",&k);
    scanf("%s",&b);

    int a_len = strlen(a);
    int b_len = strlen(b);
    if(k == '+') {
        if(a_len < b_len) {
            b[b_len - a_len] = '1';
            printf("%s",b);
        }
        else if(a_len > b_len) {
            a[a_len - b_len] = '1';
            printf("%s",a);
        }
        else {
            a[0] = '2';
            printf("%s",a);
        }
    }
    else {
        printf("1");
        for(int i=0; i<(a_len-1)+(b_len-1); i++) {
            printf("0");
        }
    }
    return 0;
}
