#include <stdio.h>
#include <stdlib.h>
int arr[21];
int a,b;
int main()
{
    for(int i=1; i<=20; i++) arr[i] = i;
    for(int i=0; i<10; i++)
    {
        scanf("%d %d",&a,&b);
        for(int i=a; i<=(a+b)/2; i++)
        {
            int t = arr[i];
            arr[i] = arr[b-i+a];
            arr[b-i+a] = t;
        }
    }
    for(int i=1; i<=20; i++) printf("%d ",arr[i]);
    return 0;
}
