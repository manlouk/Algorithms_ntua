#include<cstdio>
#include<algorithm>
#include<stdlib.h>
#include<fstream>
#include <stdio.h>
using namespace std;
long long int s[1000001],f[1000001];
int main(int argc,char *argv[]){
  long long int N,K,t,hi,lo,x;
  ifstream fin(argv[1]);
   fin>>N;fin>>K;
 long long int max=-1;long long int min=100000002;
   for(long long int j=0;j<N;j++){
        fin>>s[j];
        if(s[j]<min)min=s[j];
       fin>>f[j];
      if(f[j]>max)max=f[j];
        }
  lo=min-1;hi=1000000001;
  while(lo<hi){
      x=lo+(hi-lo)/2;
     t=0;
     for(long long int i=0;i<N;i++){
        if((x>=s[i])&&(x<=f[i]))t+=x-s[i]+1;
        else if (x>f[i]) t+=f[i]-s[i]+1;
 
        }
     if (t>=K) hi=x;
     else lo=x+1;
  }
 printf("%lld\n",hi);
 return 0;
}
