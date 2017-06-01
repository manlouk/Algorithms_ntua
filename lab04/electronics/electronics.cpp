#include<cstdio>  
#include<cstdlib>  
#include<iostream>  
#include<vector>  
#include<queue>  
  
using namespace std;  
  
#define INF 10000000   
#define hor 1  
#define ver 0  
#define start_s -1  
typedef long long int LL;  
typedef pair<int,int>ii;  
typedef pair<ii,ii>iii;  
int AdjMatrix[1001][1001];  
bool blocked_row[1001];  
bool blocked_col[1001];  
ii s,t;  
int dist[1001][1001];  
priority_queue< iii,vector<iii>,greater<iii> > pq;  
int main(){  
  int L,W;  
  scanf("%d",&L);  
  scanf("%d",&W);  
  s.first=-1;s.second=-1;t.first=-1;t.second=-1;  
  for(int i=1;i<=L;i++){  
    for(int j=1;j<=W;j++){  
       scanf("%d",&AdjMatrix[i][j]);  
       if((AdjMatrix[i][j]==0)&&(s.first==-1)){s.first=i;s.second=j;}  
       if((AdjMatrix[i][j]==0)&&(s.first!=-1)){t.first=i;t.second=j;}  
        
       }  
   }  
  /* cout<<s.first<<" "<<s.second<<"\n"; 
   cout<<t.first<<" "<<t.second<<"\n"; 
   */  
 for(int i=1;i<=L;i++){  
   for(int j=1;j<=W;j++){  
      dist[i][j]=INF;}  
 }        
 dist[s.first][s.second]=0;  
 pq.push(iii(ii(dist[s.first][s.second],start_s),ii(s.first,s.second)));  
 while(!pq.empty()){  
    iii u=pq.top();pq.pop();  
    int d=u.first.first;  
    int dir=u.first.second;  
    int r=u.second.first;  
    int c=u.second.second; 
   if(dir==ver){     
    for(int i=1;i<=L;i++){  
      if(r!=i){  
       if(AdjMatrix[i][c]==4000){
             if(i>r)break;
             else continue;
       
       }  
        if( (dir==start_s)||(dir==ver)){  
             if(d+AdjMatrix[i][c]<dist[i][c]){ dist[i][c]=AdjMatrix[i][c];pq.push(iii(ii(dist[i][c],ver),ii(i,c)));}  
         }  
        else{  
           if(dir==hor){  
           if(d+AdjMatrix[i][c]<dist[i][c]){ dist[i][c]=AdjMatrix[i][c]+d;pq.push(iii(ii(dist[i][c],ver),ii(i,c)));}  
           }  
           }  
    }       
   }  
  }
  else{ 
    for(int j=1;j<=W ;j++){  
       if(AdjMatrix[r][j]==4000){
                if(j>c)break;
                else continue;
       }  
        if(c!=j){  
         if( (dir==start_s)||(dir==hor)){  
             if(d+AdjMatrix[r][j]<dist[r][j]){ dist[r][j]=AdjMatrix[r][j];pq.push(iii(ii(dist[r][j],hor),ii(r,j)));}  
               
         }  
        else{  
          if(dir==ver){  
           if(d+AdjMatrix[r][j]<dist[r][j]) {dist[r][j]=AdjMatrix[r][j]+d;pq.push(iii(ii(dist[r][j],hor),ii(r,j)));}  
          }  
        }  
            
    }  
   }
  }   
   }  
   for(int i=1;i<=L;i++){ 
     for(int j=1;j<=W;j++)cout<<dist[i][j]<<" ";cout<<"\n";} 
        
 //printf("%d\n",dist[t.first][t.second]);  
 }      
