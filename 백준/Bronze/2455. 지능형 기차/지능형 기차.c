#include <stdio.h>
#include <stdlib.h>
int sum,a,b,max;
int main()
{
    for(int i=0; i<4; i++)
    {
        scanf("%d %d",&a,&b);
        sum -= a;
        sum += b;
        if(max < sum) max = sum;
    }
    printf("%d",max);
    return 0;
}
