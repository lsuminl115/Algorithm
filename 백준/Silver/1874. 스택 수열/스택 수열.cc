#include <stack>
#include <queue>
#include <stdio.h>
using namespace std;main(){stack<int>s;queue<char>q;int i,j,k,a,c=1,n,w=0;scanf("%d",&n);for(i=1;i<=n;i++){scanf("%d",&k);if(s.empty())a=0;else a=s.top();if(a<k){for(j=c;j<=k;j++){s.push(j);q.push('+');c++;}s.pop();q.push('-');}else if(a==k){s.pop();q.push('-');}else w=1;}if(w)printf("NO");else{while(!q.empty()){printf("%c\n",q.front());q.pop();}}}
