#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=2*n;j++)
        {
            if(j <= i || j >= (2*n-i+1)) printf("*");
            else printf(" ");
        }
        printf("\n");
    }

    for(i=n-1;i>=1;i--)
    {
        for(j=1;j<=2*n;j++)
        {
            if(j <= i || j >= (2*n-i+1)) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
