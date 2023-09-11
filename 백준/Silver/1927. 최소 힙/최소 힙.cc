#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int> > pq;
    int n,i,a;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a==0)
        {
            if(pq.empty()) printf("0\n");
            else
            {
                printf("%d\n",pq.top());
                pq.pop();
            }
        }
        else pq.push(a);
    }
    return 0;
}
