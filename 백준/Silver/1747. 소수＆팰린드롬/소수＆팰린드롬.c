#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n = 10000000;
int arr[10000001];

int f(int x)
{
    char c[8];
    sprintf(c,"%d",x);
    int len = strlen(c);
    int left = 0;
    int right = len-1;
    while(left < right)
    {
        if(c[left] != c[right]) return 0;
        left++;
        right--;
    }
    return 1;
}

int main()
{

    for(int i=2; i<=n; i++) arr[i] = 1;

    for(int i=2; i*i<=n; i++)
    {
        if(arr[i] == 0) continue;
        for(int j=i*i; j<=n; j+=i) arr[j] = 0;
    }
    int a;
    scanf("%d",&a);

    for(;;a++)
    {
        if(f(a) && arr[a]){
            printf("%d",a);
            break;
        }
    }
    return 0;
}
