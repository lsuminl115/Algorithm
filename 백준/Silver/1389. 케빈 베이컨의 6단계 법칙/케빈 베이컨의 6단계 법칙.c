#include <stdio.h>
#include <stdlib.h>
#define INF 654321
int main()
{
    int n,m,i,j,k,a,b,arr[101][101],sum[101]={0},min=INF;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)arr[i][j]=INF;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                if(arr[j][i] + arr[i][k] <= arr[j][k])
                {
                    arr[j][k] = arr[j][i] + arr[i][k];
                }
            }
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            sum[i] += arr[i][j];
        }
        if(min > sum[i]) min = sum[i];
    }

    for(i=1;i<=n;i++)
    {
        if(sum[i] == min)
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}
