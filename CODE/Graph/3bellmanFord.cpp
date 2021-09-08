// negative edge cycle is when total cost of round trip back to a vertex is negative
// an undirected graph with negative edge always result in negative edge cycle

#include<bits/stdc++.h>
#define E 10
#define V 10
using namespace std;
class Edge{
    public:
    int src,des,weight;
};

Edge edges[E];

bool bellman(int src){
    vector<int>dist(V,INT_MAX);
    dist[src]=0;
    for(int j =0;j<V-1;j++){
        for(int i=0;i<E;i++){
            int u =edges[i].src;
            int v =edges[i].des;
            int wt =edges[i].weight;
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt){
                dist[v]=dist[u]+wt;
            }
        }
    }
    // the below loop is called realxation
    for(int i=0;i<E;i++){
        int u =edges[i].src;
        int v =edges[i].des;
        int wt =edges[i].weight;
        if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt){
            return 0;
        }
    }
}
int main(){
    return 0;
}