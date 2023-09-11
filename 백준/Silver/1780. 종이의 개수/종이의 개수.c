#include <stdio.h>
#include <stdlib.h>

int n,arr[3000][3000],cnt[4];
void check(int x, int y, int k)
{
    int a, i, j;
    a = arr[x][y];
    for(i = x; i < x + k; i++)
    {
        for(j = y; j < y + k; j++)
        {
            if(a != arr[i][j])
            {
                k /= 3;
                check(x,y,k);
                check(x+k,y,k);
                check(x+k*2,y,k);

                check(x,y+k,k);
                check(x+k,y+k,k);
                check(x+k*2,y+k,k);

                check(x,y+k*2,k);
                check(x+k,y+k*2,k);
                check(x+k*2,y+k*2,k);
                return;
            }
        }
    }
    cnt[a+1]++;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    check(1,1,n);

    for(i=0; i<=2; i++)
    {
        printf("%d\n",cnt[i]);
    }
    return 0;
}
