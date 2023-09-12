#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
typedef struct
{
    int x;
    int y;
}s;
int n,check[101][101],arr[101][101],cnt=1,min_l = 9999;
int f(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > n || arr[x][y] != 0) return 0;
    else return 1;
}
void dfs(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > n || arr[x][y] == 0 || check[x][y] == 1) return;

    check[x][y] = 1;
    arr[x][y] = cnt;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

void bfs(queue<s> &q,int checkarr[][101], int num)
{
    int length = 0;
    int x,y,k,i;
    while(!q.empty())
    {
        k = q.size();
        length++;
        if(min_l < length) break;
        for(i=1;i<=k;i++)
        {
            x = q.front().x;
            y = q.front().y;
            q.pop();

            if(x < 1 || x > n || y < 1 || y > n || checkarr[x][y] == 1) continue;
            checkarr[x][y] = 1;

            if(arr[x][y] == 0)
            {
                q.push({x-1,y});

                q.push({x+1,y});

                q.push({x,y-1});

                q.push({x,y+1});
            }
            else
            {
                if(arr[x][y] == num) continue;
                else if(arr[x][y] != num)
                {
                    if(min_l > length) min_l = length;
                }
            }

        }
    }
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

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(arr[i][j] == 1)
            {
                cnt++;
                dfs(i,j);
            }
        }
    }


    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(arr[i][j] != 0)
            {
                if(f(i-1,j))
                {
                    queue<s> q;
                    int checkarr[101][101]={0};
                    q.push({i-1,j});
                    bfs(q,checkarr,arr[i][j]);
                }
                if(f(i+1,j))
                {
                    queue<s> q;
                    int checkarr[101][101]={0};
                    q.push({i+1,j});
                    bfs(q,checkarr,arr[i][j]);
                }

                if(f(i,j-1))
                {
                    queue<s> q;
                    int checkarr[101][101]={0};
                    q.push({i,j-1});
                    bfs(q,checkarr,arr[i][j]);
                }

                if(f(i,j+1))
                {
                    queue<s> q;
                    int checkarr[101][101]={0};
                    q.push({i,j+1});
                    bfs(q,checkarr,arr[i][j]);
                }
            }
        }
    }

    printf("%d",min_l-1);
    return 0;
}
