#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a,b,c,d,e,f;
    scanf("%01d%01d%01d %01d%01d%01d",&a,&b,&c,&d,&e,&f);
    if(c*100+b*10+a>f*100+e*10+d) printf("%d%d%d",c,b,a);
    else printf("%d%d%d",f,e,d);

    return 0;
}
