#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,a[1001],num[43]={0},cnt=0;
    for(i=1;i<=10;i++)
    {
        scanf("%d",&a[i]);
        num[a[i]%42]++;
    }
    for(i=0;i<=41;i++)
    {
        if(num[i]!=0) cnt++;
    }
    printf("%d",cnt);
    return 0;
}
