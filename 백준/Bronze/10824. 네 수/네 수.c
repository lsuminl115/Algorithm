#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long long m,n;
    char a[100],b[100],c[100],d[100];
    scanf("%s %s %s %s",&a,&b,&c,&d);
    strcat(a,b);
    strcat(c,d);
    m = atoll(a);
    n = atoll(c);
    printf("%lld",m+n);
    return 0;
}
