#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=n; i>=1; i--,puts(""))
    {
        for(int j=1; j<n-i+1; j++) printf(" ");
        for(int j=1; j<=i*2-1; j++) printf("*");
    }
    return 0;
}
