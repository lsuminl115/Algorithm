#include <stdio.h>
#include <algorithm>
using namespace std;int n,i,a[10001],s,j;main(){scanf("%d",&n);for(i=0;i<n;i++)scanf("%d",&a[i]);sort(a,a+n);if(n==1){printf("%d",a[0]);return 0;}i=0;while(i<=n-1){if(i==n-1){s+=a[i];i++;}if(a[i]<0){if(a[i+1]<0){s+=a[i]*a[i+1];i+=2;}else if(!a[i+1])i+=2;else{s+=a[i];i++;}}else if(!a[i])i++;else break;}j=n-1;while(j>=i){if(j==i){s+=a[j];break;}if(a[j-1]>1){s+=a[j]*a[j-1];j-=2;}else if(a[j-1]==1){s+=a[j];j--;}else{s+=a[j];j--;}}printf("%d",s);}