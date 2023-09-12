#include <stdio.h>
#include <stdlib.h>
// A : 65 , Z : 90
int r,c,check[99],max=0;
char arr[31][31];
void dfs(int x, int y, int cnt)
{

    if(check[arr[x][y]]||x<1||x>r||y<1||y>c)
    {
        if(max < cnt) max = cnt;
        return;
    }
    cnt++;
    check[arr[x][y]]=1;
    dfs(x-1,y,cnt);
    dfs(x+1,y,cnt);
    dfs(x,y-1,cnt);
    dfs(x,y+1,cnt);
    check[arr[x][y]]=0;
}

int main()
{
    int i,j;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            scanf(" %c",&arr[i][j]);
        }
    }

    dfs(1,1,0);
    printf("%d",max);
    return 0;
}
