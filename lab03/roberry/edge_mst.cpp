#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include<iostream>
#define WHITE 0
#define BLACK 2
#define GRAY 1
#define MAXN 50000
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

vector<vi> AdjList;
int colors[MAXN], d[MAXN], low[MAXN];
int timeCount;
int sure,none,maybe;
void dfs(int u,int pid) {
d[u] = low[u] = ++timeCount;
colors[u] = GRAY;
for (int j=0;j<AdjList[u].size();j++) {
int t = u, id = AdjList[u][j];
if (id == pid)
continue;
if (colors[t] == WHITE) {
dfs(t, id);
low[u] = min(low[u], low[t]);
} else {
low[u] = min(low[u], d[t]);
}
}
if (pid != -1) {
if (low[u] == d[u]) {
  sure++;
}
}
colors[u] = BLACK;
}
void markBridges() {
timeCount = 0;
int n = AdjList.size();
for (int i = 0; i < n; ++i) {
colors[i] = WHITE;
}
for (int i = 0; i < n; ++i) {
if (colors[i] == WHITE) {
dfs(i, -1);
}
}
}  
int main(){
int V,E,u, v, w;
vector< pair<int, ii> > EdgeList;
scanf("%d %d", &V, &E);
for(int i=0;i<E;i++){
  scanf("%d %d %d", &u, &v, &w);            // read the triple: (u, v, w)
  EdgeList.push_back(make_pair(w, ii(u-1, v-1))); 
  }
 sort(EdgeList.begin(),EdgeList.end());   
 UnionFind UF(V);
  sure=0;maybe=0; none=0;
  AdjList.assign(V,vi());
 for(int i=0;i<E;){
  int j=i;
   while((j<E)&&(EdgeList[j].first==EdgeList[i].first))j++;
   for(int k=i;k<j;k++){
     //cout<<"We examine edge "<<EdgeList[k].second.first+1<<" "<<EdgeList[k].second.second+1<<"\n";
     if(UF.isSameSet(EdgeList[k].second.first,EdgeList[k].second.second)){
        //cout<<"Edge "<<EdgeList[k].second.first+1<<" "<<EdgeList[k].second.second+1<<" is not used\n";
        none++;}
     else{
       //  cout<<"We insert in G' edge "<<EdgeList[k].second.first+1<<" "<<EdgeList[k].second.second+1<<"\n";
        AdjList[EdgeList[k].second.first].push_back(EdgeList[k].second.second);   
        AdjList[EdgeList[k].second.second].push_back(EdgeList[k].second.first);
     
        }
      }
      markBridges();
         for(int k=i;k<j;k++){
          UF.unionSet(EdgeList[k].second.first,EdgeList[k].second.second);
          }
     
      
    i=j;         
   }
  printf("sure=%d\n",sure);
  printf("none=%d\n",none);
  printf("maybe=%d\n",E-none-sure);       
  }
