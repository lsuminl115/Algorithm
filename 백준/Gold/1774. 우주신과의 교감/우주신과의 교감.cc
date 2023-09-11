#include <bits/stdc++.h>
using namespace std;

int getparent(int parent[], int x)
{
    if(parent[x] == x) return x;
    return parent[x] = getparent(parent,parent[x]);
}

void unionparent(int parent[], int a, int b)
{
    a = getparent(parent, a);
    b = getparent(parent, b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int sameparent(int parent[], int a, int b)
{
    a = getparent(parent, a);
    b = getparent(parent, b);
    if(a == b) return 1;
    else return 0;
}

typedef struct{
    int a;
    int b;
    double value;
}st;

int order(st a, st b)
{
    return a.value < b.value;
}
int main()
{
    int n,m,a,b;
    double X,Y,Z,answer;
    // vector<st> vec, tree;
    vector<pair<int, int> > vec;
    vector<pair<double, pair<int, int> > > tree;
    int parent[1100];
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++) parent[i] = i;
    
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&a,&b);
        //vec.push_back({a, b});
        vec.push_back(make_pair(a, b));
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            X = pow((vec[i].first - vec[j].first),2);
            Y = pow((vec[i].second - vec[j].second),2);
            Z = sqrt(X+Y);
            //tree.push_back({i+1,j+1,Z});
            tree.push_back(make_pair(Z, make_pair(i+1, j+1)));
        }
    }
    
    sort(tree.begin(), tree.end());
    
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&a,&b);
        unionparent(parent, a, b);
    }
    int size = tree.size();
    for(int i=0; i<size; i++)
    {
        if(!sameparent(parent, tree[i].second.first, tree[i].second.second))
        {
            answer += tree[i].first;
            unionparent(parent, tree[i].second.first, tree[i].second.second);
        }
    }
    
    printf("%.2lf", answer);
    return 0;
}
