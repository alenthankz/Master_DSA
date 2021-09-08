#include<bits/stdc++.h>
using namespace std;
#define V 4
#define E 4

struct Edges{
    int src;
    int des;
};


list< int > * adj =new list<int >[V];
Edges edges[E];

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

// bool isCycleL(Subset * subsets){
//     for(int i =0;i<V;i++){
//         for(list<int>::iterator it =adj[i].begin();it!=adj[i].end();it++){
//             int x =find(i,subsets);
//             int y =find(*it,subsets);
//             if(x==y)return true;
//             unionn(i,*it,subsets);
//         }
//     }
//     return false;
// }

bool isCycleE(Subset * subsets){
    for(int i =0;i<E;i++){
            int x =find(edges[i].src,subsets);
            int y =find(edges[i].des,subsets);
            if(x==y)return true;
            unionn(edges[i].src,edges[i].des,subsets);
    }
}

int main(){
    Subset subsets[V];
    for(int i =0;i<V;i++){
        subsets[i].parent=i;
        subsets[i].rank=1;
    }
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(0);

    edges[0].src=0;
    edges[0].des=1;
    edges[1].src=1;
    edges[1].des=2;
    edges[2].src=2;
    edges[2].des=3;
    edges[3].src=3;
    edges[3].des=0;

    cout<<isCycleE(subsets)<<endl;
    // cout<<isCycleL(subsets)<<endl;
    return 0;
}