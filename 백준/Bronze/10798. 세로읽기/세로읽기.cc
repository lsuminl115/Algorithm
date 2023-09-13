#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,a=0;
    char b[5][15] = {0};
    for(i=0;i<5;i++){
        scanf("%s", b[i]);
        if(strlen(b[i]) > a){
            a = strlen(b[i]);
        }
    }
    for(i=0;i<a;i++){
        for(j=0;j<5;j++){
            if(b[j][i]==NULL) continue;
        printf("%c", b[j][i]);
        }
    }
}
