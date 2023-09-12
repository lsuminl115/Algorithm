#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a, b;
    scanf("%lld %lld",&a,&b);
    printf("%lld",a-b<0?b-a:a-b);
    return 0;
}
