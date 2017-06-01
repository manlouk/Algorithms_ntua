#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<utility>
using namespace std;

int dp[501][501];
int c[501][501];
bool f[501][501];
pair<int,int> best_choice[501][501];
int N,K,M;
int main(){
//  N=500;M=500;K=1;
  cin>>N;cin>>M;cin>>K;
   for(int i=1;i<=N;i++){
     for(int j=1;j<=M;j++){
       cin>>c[i][j];dp[i][j]=-1;best_choice[i][j]=make_pair(-1,-1);}}
  dp[N-1][M]=c[N][M];dp[N][M-1]=c[N][M];best_choice[N-1][M].first=N;best_choice[N][M-1].second=M;dp[N][M]=0;
 //cout<<"Outside loop\n";
 for(int x=N;x>=1;x--){
    //cout<<"Inside loop x\n";
   for(int y=M;y>=1;y--){
     //cout<<"Inside loop y\n";
     int min=500*500*4000;
      for(int p=0;p<=K;p++){
         //cout<<"Inside loop p\n";
         if(x+p>N)break;
        for(int q=0;q<=K;q++){
            //cout<<"Inside loop q\n";
            if(y+q>M)break;
            if((p==0)&&(q==0)) continue;
        
        int   pl1=dp[x+p][y+q];
         int pl2=dp[best_choice[x+p][y+q].first][best_choice[x+p][y+q].second]+c[x+p][y+q];
           if(pl2>dp[x][y]){
              dp[x][y]=pl2;best_choice[x][y].first=x+p;best_choice[x][y].second=y+q;}     
           else if(pl2==dp[x][y]){
              if(min>=pl1){
                 min=pl1;best_choice[x][y].first=x+p;best_choice[x][y].second=y+q;}}  
           
    }
   }
 }
}
cout<<dp[1][1]<<" "<<dp[best_choice[1][1].first][best_choice[1][1].second]<<"\n";
}

