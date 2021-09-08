#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src,dest,weight;
};
class Graph{
    public:
    int V,E;
    Edge *edge;
    Graph(int v,int e){
        this->E=e;
        this->V=v;
        this->edge=new Edge[e];
    }
};

struct Subset{
    int parent,rank;
};

int find(int i,Subset * subsets){
    if(subsets[i].parent!=i){
        return find(subsets[i].parent,subsets);
    }
    else return subsets[i].parent;
}
void unionn(int x,int y,Subset * subsets){
    int xroot =find(x,subsets);
    int yroot =find(y,subsets);
    if(subsets[xroot].rank>subsets[yroot].rank)subsets[yroot].parent=xroot;
    else if(subsets[xroot].rank<subsets[yroot].rank)subsets[xroot].parent=yroot;
    else {
        subsets[yroot].parent=xroot;subsets[xroot].rank++;
    }
}

int myComp(const Edge & a,const Edge & b){
    return a.weight>b.weight;
}
void KruskalMST(Graph * graph){
     Subset subsets[graph->V];
     for(int i =0;i<graph->V;i++){
        subsets[i].parent=i;
        subsets[i].rank=1;
     }
    int i =0,e=0;
    vector<Edge>MST(graph->V-1,{0,0,0});
    sort(graph->edge,graph->edge+graph->E,myComp);
    while(e<graph->V-1 && i<graph->E){
        Edge curr_edge =graph->edge[i++];
        int x = find(graph->edge[i].src,subsets);
        int y = find(graph->edge[i].dest,subsets);
        if(x!=y){
            MST[e++]=curr_edge;
            unionn(x,y,subsets);
        }
    }
    
}

int main(){
     Graph * graph =new Graph(4,5);
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
 
    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
 
    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
 
    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
 
    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
 
    KruskalMST(graph);
    return 0;
   
}