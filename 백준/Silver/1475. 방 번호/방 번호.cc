#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,a,b=0,c[10]={0};
	scanf("%d",&a);
	for(i=1;a/i>0;i*=10){
		c[a%(i*10)/i]++;
		a-=a%i;
	}
	for(i=0;i<10;i++)
		if(b<c[i])
			if(i==9||i==6){
                b=(c[9]+c[6]+1)/2;
			}
			else b=c[i];
	printf("%d",b);
}
