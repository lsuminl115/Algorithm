#include <stdio.h>
#include <vector>
#define S 100001
using namespace std;typedef struct{int d,u;}s;vector<s>v[S];bool c[S],C[S];int q,Q,i,a,b,n,m,d;void D(bool z[S],int k,int Y){int x,y,t;z[k]=1;for(t=0;t<v[k].size();t++){x=v[k][t].d;y=v[k][t].u;if(z[x]){if(q<Y){Q=k;q=Y;}continue;}D(z,x,Y+y);}}main(){scanf("%d",&n);for(i=1;i<=n;i++){scanf("%d",&m);while(1){scanf("%d",&a);if(a==-1)break;scanf("%d",&b);v[m].push_back({a,b});}}D(c,1,0);d=Q;q=0;D(C,d,0);printf("%d",q);}