#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a=0,b=0,c=0,d=0,i;
    char arr[101];
    while(gets(arr) != NULL)
    {
        a = 0, b = 0, c = 0, d = 0;
        for(i=0;i<strlen(arr);i++)
        {
            if(arr[i] >= 'a' && arr[i] <= 'z') a++;
            else if(arr[i] >= 'A' && arr[i] <= 'Z') b++;
            else if(arr[i] >= '0' && arr[i] <= '9') c++;
            else d++;
        }
        printf("%d %d %d %d\n",a,b,c,d);
    }
    return 0;
}
