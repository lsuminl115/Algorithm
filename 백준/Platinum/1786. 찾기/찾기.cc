#include <bits/stdc++.h>

using namespace std;

vector<int> make_table(char str[])
{
    int str_size = strlen(str);
    vector<int> table(str_size,0);
    int j = 0;

    for(int i=1; i<str_size; i++)
    {
        while(j > 0 && str[i] != str[j]) j = table[j-1];
        if(str[i] == str[j]) table[i] = ++j;
    }
    return table;
}

void KMP(char a[], char b[])
{
    vector<int> table = make_table(b);
    queue<int> q;
    int al = strlen(a);
    int bl = strlen(b);
    int j=0;
    int cnt=0;
    for(int i=0; i<al; i++)
    {
        while(j > 0 && a[i]!=b[j]) j = table[j-1];
        if(a[i] == b[j])
        {
            if(j == bl-1)
            {
                cnt++;
                q.push(i-bl+2);
                j = table[j];
            }
            else j++;
        }
    }
    printf("%d\n",cnt);
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop();
    }
}
int main()
{

    char arr1[1000002],arr2[1000002];
    gets(arr1);
    gets(arr2);
    KMP(arr1,arr2);


    return 0;
}
