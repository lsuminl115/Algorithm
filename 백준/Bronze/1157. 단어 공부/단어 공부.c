#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char arr[1000001];
int a[30];
int main()
{
    int t;
    int max = 0, p = 0, index = 0;
    scanf("%s",&arr);
    t = strlen(arr);
    for(int i=0; i<t; i++)
    {
        if('A' <= arr[i] && arr[i] <= 'Z') arr[i] += 32;
        a[arr[i]-97]++;
    }

    for(int i=0; i<26; i++)
    {
        if(max < a[i]) max = a[i];
    }
    for(int i=0; i<26; i++)
    {
        if(max == a[i])
        {
            index = i;
            p++;
        }
    }
    if(p == 1) printf("%c",index + 65);
    else printf("?");
    return 0;
}
