#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,i,t=0,d,c;
    scanf("%d",&n);
    while(t!=n){
        scanf("%d %d",&a,&b);
        if(a>=b){
                for(i=1;i<=b;i++){
                if(((a*i)%b)==0){
                    d=a*i;
                    printf("%d ",d);
                    break;
                }
            }
        }
        else if(a<=b){
                for(i=1;i<=a;i++){
                if(((b*i)%a)==0){
                    d=b*i;
                    printf("%d ",d);
                    break;
                }
            }
        }
        if(a>=b){
            for(i=1;i<=b;i++){
                if(a%i==0 && b%i==0){
                    c=i;
                }

            }
            printf("%d\n",c);
        }
        else if(a<=b){
            for(i=1;i<=a;i++){
                if(a%i==0 && b%i==0){
                    c=i;
                }
            }
            printf("%d\n",c);

        }
        t++;
    }
    return 0;
}
