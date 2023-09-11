#include <stdio.h>
#include <stdlib.h>
int n,m,arr[60][60];
void dfs(int x, int y)
{
    if(x < 0 || x > n || y < 0 || y > m) return;
    else if(arr[x][y] == 0) return;
    else
    {
        arr[x][y] = 0;
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
    }
}
int main()
{
    int k,i,j,q,cnt=0,l,x,y;
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        cnt=0;
        scanf("%d %d %d",&n,&m,&l);
        for(j=1;j<=l;j++)
        {
            scanf("%d %d",&x,&y);
            arr[x][y] = 1;
        }

        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                if(arr[j][k] != 0)
                {
                    cnt++;
                    dfs(j,k);
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
