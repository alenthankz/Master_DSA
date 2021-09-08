#include<bits/stdc++.h>
using namespace std;
#define V 5
int getMin(vector<int>&dist,vector<int>&mst){
    int min=INT_MAX,ind;
    for(int i =0;i<V;i++){
        if(!mst[i]){
            if(dist[i]<min){
                ind =i;min=dist[i];
            }
        }
    }
    return ind;
}
void printMST(vector<int>&parent, int graph[V][V])  
{  
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < V; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}  
void primMST(int graph[][V]){
    vector<int>dist(V,INT_MAX);
    vector<int>MST(V-1,0);
    vector<int>parent(V,-1);

    dist[0]=0;
    for(int i =0;i<V-1;i++){ //hereit V-1 only difference from dijstra
        int u =getMin(dist,MST);
        MST[u]=1;
        for(int j =0;j<V;j++){
            if(graph[u][j] && !MST[j] && graph[u][j]<dist[j]){
                dist[j]=graph[u][j];parent[j]=u;
            }
        }
    }
    printMST(parent,graph);
}
// parent here is intialised -1 whereas in lis it is 'i' itself
int main(){
    int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
  
    // Print the solution  
    primMST(graph);  
  
    return 0;
}