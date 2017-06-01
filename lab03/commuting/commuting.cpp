#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<utility>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<long,long> ii;
typedef vector<long>vi;
typedef vector<ii > vii;
typedef vector< pair<long,ii> > EdgeList;
//typedef priority_queue<int,ii> Edge;
class UnionFind {                                             // OOP style

private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
 UnionFind(int N) {
 setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
 p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
 int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
 bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

 void unionSet(long i, long j) { 
   if (!isSameSet(i, j)) { numSets--; 
     int x = findSet(i), y = findSet(j);
   if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }

    else { p[x] = y; setSize[y] += setSize[x];

          if (rank[x] == rank[y]) rank[y]++; } } }

  int numDisjointSets() { return numSets; }

  long sizeOfSet(long i) { return setSize[findSet(i)]; }

};

//int t[5000000];
int main(){
  int N,M,K;
  long ta,tb,w;
  EdgeList e;
  int e1[300000];
  cin>>N>>M>>K;
 UnionFind UF(N);
  for(int i=0;i<M;i++){
    cin>>ta>>tb>>w;
     e.push_back(make_pair(-w,ii(ta-1,tb-1)));
//    t[i]=0;
    }
 sort(e.begin(),e.end());
  long min=1;
 int mst_edge=0;
  for(int i=0;i<M;i++){
    if(!UF.isSameSet(e[i].second.first,e[i].second.second)){
    //    min=e[i].first;
      UF.unionSet(e[i].second.first,e[i].second.second);
      e1[mst_edge]=-e[i].first;
     mst_edge++;
      // cout<<e[i].second.first+1<<","<<e[i].second.second+1<<"\n";
     //mst_edges++;}}
    }
 }
sort(e1,e1+mst_edge);
//for(int i=0;i<mst_edge;i++)cout<<e1[i]<<"\n";
if(K>=mst_edge)cout<<"infinity\n";
else cout<<e1[K]<<"\n";
}
