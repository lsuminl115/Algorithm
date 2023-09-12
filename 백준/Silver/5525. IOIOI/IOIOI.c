#include <stdio.h>
#include <stdlib.h>
int n,m,dp[1000001],cnt,count;
char arr[1000001];
int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    scanf(" %s",&arr);

    for(int i=0; i<m-2; i++)
    {
        if(arr[i]=='I'&&arr[i+1]=='O'&&arr[i+2]=='I')
        {
            dp[i] = ++cnt;
            i++;
        }
        else
        {
            dp[i] = 0;
            cnt=0;
        }
    }
    for(int i=0;i<m-2;i++)
    {
        if(dp[i] >= n) count++;
    }
    printf("%d",count);
    return 0;
}
