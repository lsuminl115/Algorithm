#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a;
    vector<int> v;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++)
    {
        printf("%d\n",v[i]);
    }
    return 0;
}
