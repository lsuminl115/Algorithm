#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a;
    scanf("%d",&n);
    for(;;)
    {
        scanf("%d",&a);
        if(!a) break;
        if(a%n==0) printf("%d is a multiple of %d.\n",a,n);
        else printf("%d is NOT a multiple of %d.\n",a,n);
    }
    return 0;
}
