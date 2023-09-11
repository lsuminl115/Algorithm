#include <stdio.h>
#include <stdlib.h>
long long int gcd(long long int a, long long int b)
{
    return !b?a:gcd(b, a%b);
}
int main()
{
    long long int a,b,t;
    scanf("%lld %lld",&a,&b);
    t = gcd(a, b);
    for(int i=0; i<t; i++) printf("1");
    return 0;
}
