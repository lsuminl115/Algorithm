#include <stdio.h>
#include <stdlib.h>
int n,A,B;
char a;
int main()
{
    for(scanf("%d ",&n);n--;)
    {
        scanf(" %c",&a);
        if(a=='A') A++;
        else B++;
    }
    puts(A<B?"B":A>B?"A":"Tie");
    return 0;
}
