#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,e,hap=0;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    hap=(a*a)+(b*b)+(c*c)+(d*d)+(e*e);
    printf("%d",hap%10);
    return 0;
}
