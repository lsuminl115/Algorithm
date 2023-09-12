#include <stdio.h>
#include <stdlib.h>

int f(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    else
    {
        int k=0;
        for(int i=1;i<=b;i++)
        {
            k += f(a-1,i);
        }
        return k;
    }
}


int main()
{
    int n,i,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        printf("%d\n",f(a,b));
    }
    return 0;
}
