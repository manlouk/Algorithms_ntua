#include<cstdio>
#include<algorithm>
using namespace std;
typedef  long long int LL;
typedef  long int L;
typedef pair<L,L>ii;
bool comp(ii a,ii b){return a.first<b.first;}
LL dx[500001],dy[500001],sumx,sumy;
ii x[500001],y[500001];
int main(){
    int n;
    scanf("%d",&n);
    sumx=0;sumy=0;
    for(int i=0;i<n;i++){
      scanf("%ld",&x[i].first);
      scanf("%ld",&y[i].first);
      x[i].second=i;y[i].second=i;
      sumx+=x[i].first;sumy+=y[i].first;
      dx[i]=0;dy[i]=0;
    }
    sort(x,x+n,comp);
    sort(y,y+n,comp);
    
    dx[x[0].second]=sumx-n*x[0].first;
    dy[y[0].second]=sumy-n*y[0].first;
   for(int i=1;i<n;i++){
      dx[x[i].second]=dx[x[i-1].second]+(x[i].first-x[i-1].first)*(2*i-n);
      dy[y[i].second]=dy[y[i-1].second]+(y[i].first-y[i-1].first)*(2*i-n);
   }
   LL min=sumx+sumy;
   for(int i=0;i<n;i++){
      if(dx[i]+dy[i]<min)
        min=dx[i]+dy[i];
   }
  printf("%lld\n",min);
 return 0;
}
    
