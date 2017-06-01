#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#define INF 10000000
using namespace std;
typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;
vector<vi> AdjList;
vi p;
vi d;
 int maxD=-1;
 int max_p,diam;
     int leaf;
     int height;
 int D[100001][3];
 int h[100001];
void BFS(int s){
      
       queue<int> q;q.push(s);
       int u; 
 while (!q.empty()) {
     u = q.front(); q.pop();                        // queue: layer by layer!
   // if (dist[u] != layer) printf("\nLayer %d: ", dist[u]);
   // layer = dist[u];
   // printf("visit %d, ", u);
   //cout<<"U:"<<(int)AdjList[u].size()<<"\n";
    for (int j = 1; j < (int)AdjList[u].size(); j++) {
      int v = AdjList[u][j];
     // cout<<"dist: "<<dist[v]<<"\n";                           // for each neighbors of u
      if (d[v] == 0) {
      //cout<<"Inside\n";
      d[v]=1;
       // dist[v] = dist[u] + 1;                  // v unvisited + reachable
        p[v] = u;          // addition: the parent of vertex v->first is u
        q.push(v);                              // enqueue v for next step
      }
     
    }  
 }
 cout<<"u:"<<u<<"\n";
 int last_node=p[u];
 height=0;
 while(last_node>0){
        last_node=p[last_node];
        //cout<<"u "<<last_node<<"\n";
        height++;
        
        }
  //res.height=height      
  leaf=u;      
  
         
}  
int main(){
        
        int K,x,N;
        // printf("1\n");
        scanf("%d",&K);
        for(int i=0;i<K;i++){
                
                scanf("%d",&N);
                AdjList.assign(100001,vi());
                if(N==1){
                     scanf("%d",&x);
                    h[i]=0;}
              else if(N==2){scanf("%d",&x);h[i]=1;}    
              else{
                  for(int j=1;j<N;j++){
                        scanf("%d",&x); 
                        AdjList[x].push_back(j+1);
                        AdjList[j+1].push_back(x);
                        }
                        
               }
               
                   
              // cout<<"size: "<<AdjList[1].size()<<"\n"; 
               d.assign(100000,0);
               p.assign(100000, -1);
               BFS(1);
               h[i]=height;
               p.clear();d.clear();
               cout<<"height: "<<h[i]<<"\n";
               d.assign(100000,0);
               p.assign(100000, -1);
               BFS(leaf);
               diam=height;
               if(diam>maxD){maxD=diam;max_p=i;}
               AdjList.clear();p.clear();d.clear();
               
                              
        }
       for (int i = 0; i <= K; i++)
		D[i][0] = 0; 
	for (int i = 0; i <= 2; i++) 
		D[0][i] = 0;
		
	//Dynamic Programming to compute the max distance between every planet couple.
	for (int i = 1; i <= K; i++) {
		D[i][1] = max(h[i-1] + i, D[i-1][1]);	
		D[i][2] = max(h[i-1] + D[i-1][1], 1 + D[i-1][2]);
	} 
        printf("%d\n", max(maxD, D[K][2]));
	return 0;
}
        
        
                        
