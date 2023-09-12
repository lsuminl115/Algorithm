#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,k,arr[99999],a,sum=0,i=2,j;
    scanf("%d %d",&n,&k);
    arr[1] = n;
    while(1)
    {
        sum = 0;

        while(n!=0)
        {
            a = n%10;
            if(k==1) sum += a;
            else if(k==2) sum += a*a;
            else if(k==3) sum += a*a*a;
            else if(k==4) sum += a*a*a*a;
            else if(k==5) sum += a*a*a*a*a;
            n/=10;
        }

        n = sum;
        for(j = 1; j <= i; j++)
        {
            if(arr[j] == n)
            {
                printf("%d",j-1);
                return 0;
            }
        }
        arr[i] = n;
        i++;
    }
    return 0;
}
