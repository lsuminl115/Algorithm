#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,max=0;
    double sum=0,arr[1001];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lf",&arr[i]);
        if(max < arr[i]) max = arr[i];
    }
    for(i=1;i<=n;i++)
    {
        arr[i] = arr[i]/max*100;

        sum += arr[i];
    }

    printf("%g",sum/n);


    return 0;
}
