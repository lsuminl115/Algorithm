#include <stdio.h>
#include <stdlib.h>
int max,index;
int main()
{
    int a,b,c,d;
    for(int i=0; i<5; i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(max<a+b+c+d)
        {
            index = i+1;
            max = a+b+c+d;
        }
    }
    printf("%d %d",index,max);
    return 0;
}
