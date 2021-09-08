#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define V 4

int main(){
     int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
    vector< vector<int> >dist(V,vector<int>(V,INF));
    for(int i =0;i<V;i++){
        for(int j =0;j<V;j++){
            dist[i][j]=graph[i][j];
        }
    }
    // min distance to all vertex from all vertex ( not single source)
    for(int k =0;k<V;k++){
        for(int i =0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    return 0;
}