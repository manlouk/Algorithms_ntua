#include<cstdio>    
#include<cstdlib>    
#include<iostream>    
#include<vector>    
#include<queue>    
    
using namespace std;    
    
#define INF 10000000     
#define up 1    
#define down 2  
#define right 3  
#define left 4   
#define start_s -1    
typedef long long int LL;    
typedef pair<int,int>ii;    
typedef pair<ii,ii>iii;    
int AdjMatrix[1001][1001];     
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
          dist[i][j]=INF;  
   }    
 }   
          
  dist[s.first][s.second]=0;  
    
 /* for(int i=1;i<=L;i++){   
       if(AdjMatrix[i][s.second]==4000)break; 
       dist[i][s.second]=AdjMatrix[i][s.second];} 
  for(int j=1;j<=W;j++){ 
     if(AdjMatrix[s.first][j]==4000)break; 
     dist[s.first][j]=AdjMatrix[s.first][j];}   
   */      
  /* for(int i=1;i<=L;i++){  
     for(int j=1;j<=W;j++)cout<<dist[i][j]<<" ";cout<<"\n";}    
  */  
        
 pq.push(iii(ii(dist[s.first][s.second],start_s),ii(s.first,s.second)));    
 while(!pq.empty()){    
    iii u=pq.top();pq.pop();    
    int d=u.first.first;    
    int dir=u.first.second;    
    int r=u.second.first;    
    int c=u.second.second;  
    if(dir==start_s){  
       for(int i=s.first;i>=1;i--){  
                if(AdjMatrix[i][s.second]==4000)break;  
                else{  
                        if(d+AdjMatrix[i][s.second]<dist[i][s.second]){  
                                dist[i][s.second]=AdjMatrix[i][s.second]+d;  
                                pq.push(iii(ii(dist[i][s.second],up),ii(i,s.second)));  
                        }  
                }  
         
       }  
       for(int i=s.first;i<=L;i++){  
         
       if(AdjMatrix[i][s.second]==4000)break;  
                else{  
                        if(d+AdjMatrix[i][s.second]<dist[i][s.second]){  
                                dist[i][s.second]=AdjMatrix[i][s.second]+d;  
                                pq.push(iii(ii(dist[i][s.second],down),ii(i,s.second)));  
                        }  
                }  
         
       }  
       for(int j=s.second;j<=W;j++){  
         
       if(AdjMatrix[s.first][j]==4000)break;  
                else{  
                        if(d+AdjMatrix[s.first][j]<dist[s.first][j]){  
                                dist[s.first][j]=AdjMatrix[s.first][j]+d;  
                                pq.push(iii(ii(dist[s.first][j],right),ii(s.first,j)));  
                        }  
                }  
         
       }  
          for(int j=s.second;j>=1;j--){  
         
       if(AdjMatrix[s.first][j]==4000)break;  
                else{  
                        if(d+AdjMatrix[s.first][j]<dist[s.first][j]){  
                                dist[s.first][j]=AdjMatrix[s.first][j]+d;  
                                pq.push(iii(ii(dist[s.first][j],left),ii(s.first,j)));  
                        }  
                }  
         
       }  
    }  
   else{  
        if(dir==up||dir==down){  
                for(int j=c;j>=1;j--){  
                        if(AdjMatrix[r][j]==4000)break;  
                        if(d+AdjMatrix[r][j]<dist[r][j]){  
                                dist[r][j]=AdjMatrix[r][j]+d;  
                                pq.push(iii(ii(dist[r][j],left),ii(r,j)));  
                       }  
                }  
             for(int j=c;j<=W;j++)  
             {  
                        if(AdjMatrix[r][j]==4000)break;  
                        if(d+AdjMatrix[r][j]<dist[r][j]){  
                                dist[r][j]=AdjMatrix[r][j]+d;  
                                pq.push(iii(ii(dist[r][j],right),ii(r,j)));  
                       }  
                }  
        }  
        else{  
                        for(int i=r;i>=1;i--){  
                        if(AdjMatrix[i][c]==4000)break;  
                        if(d+AdjMatrix[i][c]<dist[i][c]){  
                                dist[i][c]=AdjMatrix[i][c]+d;  
                                pq.push(iii(ii(dist[i][c],up),ii(i,c)));  
                       }  
                }  
             for(int i=r;i<=L;i++)  
             {  
                        if(AdjMatrix[i][c]==4000)break;  
                        if(d+AdjMatrix[i][c]<dist[i][c]){  
                                dist[i][c]=AdjMatrix[i][c]+d;  
                                pq.push(iii(ii(dist[i][c],down),ii(i,c)));  
                       }  
                }  
        }  
                  
          
          
          
          
        }  
    }      
     
   /* for(int i=1;i<=L;i++){  
     for(int j=1;j<=W;j++)cout<<dist[i][j]<<" ";cout<<"\n";} 
   */  
   printf("%d\n",dist[t.first][t.second]);  
   }  
        
