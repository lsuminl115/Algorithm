#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main()
{
    int i,a[10],b[10];
    for(i=0;i<3;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<2;i++){
        scanf("%d",&b[i]);
    }
    sort(a,a+3);
    sort(b,b+2);
    printf("%d",a[0]+b[0]-50);
    return 0;
}
