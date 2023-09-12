#include <bits/stdc++.h>
using namespace std;
long long int arr[80001];
int main()
{
    int n,a,m;
    long long int sum = 0;
    stack<int> s1;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a);
        if(s1.empty()) s1.push(a);
        else
        {
            while(!s1.empty())
            {
                if(s1.top() > a) break;
                s1.pop();
            }
            s1.push(a);
        }
        arr[i] = s1.size() - 1;
        sum += arr[i];
    }
    printf("%lld",sum);

    return 0;
}
