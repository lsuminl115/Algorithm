#include <stdio.h>
#include <stdlib.h>
int max,i,j,a,x,y;
int main()
{

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            scanf("%d",&a);
            if(max < a)
            {
                x = i;
                y = j;
                max = a;
            }
        }
    }
    printf("%d\n%d %d",max, x+1, y+1);
    return 0;
}
