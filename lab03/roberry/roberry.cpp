#include<cstdio>
#include<iostream>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int>ii;
typedef priority_queue<pair<int,ii> >EdgeList;


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

EdgeList e;
int main(){
   int surely,maybe,not_even_close;
   int N,M,v1,v2,w;
  // EdgeList e;
   cin>>N>>M;
   UnionFind UF(N);
   for(int i=1;i<=M;i++){
     cin>>v1>>v2>>w;
      e.push(make_pair(-w,ii(v1-1,v2-1)));}
  int max=-1;
  surely=0;maybe=0;not_even_close=0;
 while(UF.numDisjointSets()!=1){
   if(!UF.isSameSet(e.top().second.first,e.top().second.second)){
   UF.unionSet(e.top().second.first,e.top().second.second);
   if(max<-e.top().first){max=-e.top().first;surely++;}
   else {maybe++;max=-e.top().first;}}
   e.pop();
  }
 
 while(!e.empty()){
     if(max==-e.top().first){maybe++;} 
     else not_even_close++;
    e.pop();
  }  
cout<<surely-1<<"\n"<<not_even_close<<"\n"<<maybe+1<<"\n";
}             
   
