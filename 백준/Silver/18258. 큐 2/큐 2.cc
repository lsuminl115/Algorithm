#include <bits/stdc++.h>
using namespace std;
char arr[6];
int main()
{
    int n,a;
    queue<int> q;
    for(scanf("%d ",&n);n--;)
    {
        scanf("%s",arr);
        if(arr[0] == 'p')
        {
            if(arr[1] =='u')
            {
                scanf("%d ",&a);
                q.push(a);
            }
            else
            {
                if(q.empty()) printf("-1\n");
                else
                {
                    printf("%d\n",q.front());
                    q.pop();
                }
            }
        }
        else if(arr[0] == 's')
        {
            printf("%d\n",q.size());
        }
        else if(arr[0] == 'e')
        {
            printf("%d\n",q.empty());
        }
        else if(arr[0] == 'f')
        {
            if(q.empty()) printf("-1\n");
            else printf("%d\n",q.front());
        }
        else
        {
            if(q.empty()) printf("-1\n");
            else printf("%d\n",q.back());
        }
    }
    return 0;
}
