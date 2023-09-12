#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    for(;;)
    {
        scanf("%d %d",&a,&b);
        if(!a&&!b) break;
        if(a>b)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
