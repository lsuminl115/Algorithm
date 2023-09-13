#include <bits/stdc++.h>
using namespace std;
int check[1001];
int main()
{
    int n,a, ans;
    vector<int> v;
    scanf("%d",&n);
    ans = n;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++)
    {
        if(check[i]) continue;
        int x = v[i];
        for(int j=i+1; j<n; j++)
        {
            if(x < v[j])
            {
                if(check[j]) continue;
                x = v[j];
                ans--;
                check[j] = 1;
            }
        }
    }
    printf("%d",ans);

    return 0;
}
