#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[101];
    int i,b[200] = {0};
    scanf("%s",a);
    for(i='a';i<='z';i++)
    {
        b[i]--;
    }
    for(i=0;i<strlen(a);i++)
    {
        if(b[a[i]]==-1) b[a[i]]=i;
    }

    for(i='a';i<='z';i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}
