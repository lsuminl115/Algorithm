#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,ger[6]={500,100,50,10,5,1},jan,cnt=0,i;
    scanf("%d",&n);
    jan = 1000-n;
    for(i=0;i<6;i++){
        while(ger[i]<=jan){
            jan=jan-ger[i];
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
