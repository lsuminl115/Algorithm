#include <stdio.h>
#include <stdlib.h>
int t,cnt;
char a[102];
int main()
{
    scanf("%s",a);
    t = strlen(a);
    for(int i=0; i<t; i++)
    {
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u') cnt++;
    }
    printf("%d",cnt);
    return 0;
}
