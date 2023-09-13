#include <bits/stdc++.h>
using namespace std;
int power[1001];
int getparent(int parent[], int x)
{
    if(parent[x] == x) return x;
    return parent[x] = getparent(parent, parent[x]);
}

void unionparent(int parent[], int a, int b)
{
    a = getparent(parent, a);
    b = getparent(parent, b);
    
    if(power[a]) parent[b] = a;
    else if(power[b]) parent[a] = b;
    else
    {
        if(a < b) parent[b] = a;
        else parent[a] = b;
    }
}

int sameparent(int parent[], int a, int b)
{
    a = getparent(parent, a);
    b = getparent(parent, b);
    
    if(a == b) return 1;
    return 0;
}
typedef struct{
    int a;
    int b;
    int value;
}st;

int order(st a, st b)
{
    return a.value < b.value;
}
int main()
{
    int n,m,k,parent[1001],p,a,b,c,answer=0;
    vector<st> vec;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1; i<=n; i++) parent[i] = i;

    for(int i=0; i<k; i++)
    {
        scanf("%d",&p);
        power[p] = 1;
    }
    
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        vec.push_back({a,b,c});
    }
    sort(vec.begin(), vec.end(), order);
    
    for(int i=0; i<m; i++)
    {
        if(!sameparent(parent, vec[i].a, vec[i].b)) 
        {
            if(!(power[getparent(parent, vec[i].a)] && power[getparent(parent, vec[i].b)]))
            {
                answer += vec[i].value;
                unionparent(parent, vec[i].a, vec[i].b);
                
            }

        }
    }
    printf("%d",answer);
    return 0;
}


