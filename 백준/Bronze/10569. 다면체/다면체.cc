#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,n,m,i;
    scanf("%d",&a);
    for(i=1;i<=a;i++){
        scanf("%d %d",&m,&n);
        printf("%d\n",n-m+2);
    }
    return 0;
}
