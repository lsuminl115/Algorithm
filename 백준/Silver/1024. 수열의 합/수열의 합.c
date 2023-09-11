#include <stdio.h>
#include <stdlib.h>
int n,l,left,right,sum,min=101,a,b,i;
int main()
{
    scanf("%d %d",&n,&l);
    while(left<=right)
    {
        if(sum < n)
        {
            right++;
            sum += right;
        }
        else if(sum > n)
        {
            sum -= left;
            left++;
        }
        else
        {
            int len = right-left+1;
            if(len >= l)
            {
                if(min > len)
                {
                    min = len;
                    a = left;
                    b = right;
                }
            }
            sum -= left;
            left++;
        }

    }
    if(min == 101) printf("-1");
    else for(i=a;i<=b;i++) printf("%d ",i);
    return 0;
}
