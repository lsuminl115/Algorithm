#include <bits/stdc++.h>

using namespace std;
vector<int> make_table(char arr[])
{
    int arrsize = strlen(arr);
    vector<int> table(arrsize,0);

    int j=0;
    for(int i=1;i<arrsize;i++)
    {
        while(j>0&&arr[i]!=arr[j]) j=table[j-1];
        if(arr[i]==arr[j]) table[i] = ++j;
    }
    return table;
}
int main()
{
    int n;
    char a[1000001];
    scanf("%d",&n);
    scanf(" %s",&a);
    vector<int> table = make_table(a);
    printf("%d",n-table[n-1]);
    return 0;
}
