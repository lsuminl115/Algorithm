#include <stdio.h>
#include <stdlib.h>
int p1,p2;
int main()
{
    int n,m;
    char a,b;
    for(scanf("%d",&n);n--;)
    {
        for(scanf("%d",&m);m--;)
        {
            scanf(" %c %c",&a,&b);
            if(a=='R'&&b=='P') p2++;
            if(a=='R'&&b=='S') p1++;

            if(a=='P'&&b=='R') p1++;
            if(a=='P'&&b=='S') p2++;

            if(a=='S'&&b=='R') p2++;
            if(a=='S'&&b=='P') p1++;
        }
        puts(p1<p2?"Player 2":p1>p2?"Player 1":"TIE");
        p1 = 0;
        p2 = 0;
    }
    return 0;
}
