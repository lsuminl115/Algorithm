#include <bits/stdc++.h>
using namespace std;
typedef struct {
    long long int a;
    long long int b;
}st;
int arr[100001];
int main()
{
    stack<st> s;
    long long int value;
    int n;
    while(1)
    {
        long long int answer = 0;
        scanf("%d",&n);
        if(n == 0) break;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&arr[i]);
        }
        s.push({arr[1],1});
        for(int i=1; i<=n; i++)
        {
            st a = s.top();
            value = a.a * (i-a.b+1);
            answer = answer < value ? value : answer;
            if(i == n) break;

            if(a.a < arr[i+1])
            {
                s.push({arr[i+1], i+1});
            }
            else if(a.a > arr[i+1])
            {
                while(!s.empty())
                {
                    if(s.top().a <= arr[i+1]) break;
                    a = s.top();
                    s.pop();

                    value = a.a*(i-a.b+1);
                    answer = answer < value ? value : answer;
                }
                if(a.a > arr[i+1]) s.push({arr[i+1], a.b});
                else if(a.a < arr[i+1]) s.push({arr[i+1], i+1});
                else continue;
            }
            else
            {
                continue;
            }
        }
        while(!s.empty())
        {
            st a = s.top();
            s.pop();

            value = a.a*(n-a.b+1);
            answer = answer < value ? value : answer;
        }
        printf("%lld\n",answer);

    }


    return 0;
}
