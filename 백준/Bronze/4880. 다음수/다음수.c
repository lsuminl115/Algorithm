#include <stdio.h>
#include <stdlib.h>
int a,b,c,d1,d2;
int main()
{
    for(;;puts(""))
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a==0&&b==0&&c==0) break;

        d1 = b-a;
        d2 = c-b;
        if(d1==d2) printf("%s %d","AP",c+d1);
        else printf("%s %d","GP",c*(b/a));
    }
    return 0;
}
