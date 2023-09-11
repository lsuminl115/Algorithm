#include <stdio.h>
#include <stdlib.h>
int arr[100001];
int main()
{
    int n,i,sum = 0, max = -9999,check = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i] >= 0) check = 1;
    }
    if(check == 0)
    {
        for(i=1;i<=n;i++)
        {
            sum = arr[i];
            if(max < sum) max = sum;
        }
    }
    else
    {


    for(i=1;i<=n;i++)
    {
            sum += arr[i];
            if(sum < 0)
            {
                sum = 0;
                continue;
            }
            else
            {
                if(max < sum) max = sum;
            }
        }
    }
    printf("%d",max);
    return 0;
}
