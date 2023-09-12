#include <stdio.h>
#include <stdlib.h>
int arr[100][100],a,b;
void dfs(int x, int y)
{
    if(x < 0 || x > b || y < 0 || y > a) return ;
    else if(arr[x][y] == 0) return ;
    arr[x][y] = 0;
    dfs(x-1,y-1);
    dfs(x-1,y);
    dfs(x-1,y+1);

    dfs(x,y-1);
    dfs(x,y+1);

    dfs(x+1,y-1);
    dfs(x+1,y);
    dfs(x+1,y+1);
}


int main()
{
    int cnt=0,i,j;
    while(1)
    {
        cnt = 0;
        scanf("%d %d",&a,&b);
        if(a==0 && b==0) break;

        for(i=1;i<=b;i++)
        {
            for(j=1;j<=a;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }

        for(i=1;i<=b;i++)
        {
            for(j=1;j<=a;j++)
            {
                if(arr[i][j] == 1)
                {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",cnt);

    }
    return 0;
}
