// strongly connected component are those group of vertexex if we take any vertex of scc we can reach all vertexex of scc
// scc wont change even if the directions of the egdes are reversed

#include<bits/stdc++.h>
using namespace std;
#define V 10
vector < vector<int> > adj(V);
vector < vector<int> > adjRev(V);

void dfsStk(vector<int>&visited , int u,stack<int>stk){
    visited[u]=1;
    for(vector<int>::iterator it = adj[u].begin();it!=adj[u].end();it++){
        if(!visited[*it]){
            dfsStk(visited,*it,stk);
        }
    }
    stk.push(u);
}

void dfs(vector<int>&visited , int u){
    cout<<u<<" ";
    visited[u]=1;
    for(vector<int>::iterator it = adj[u].begin();it!=adj[u].end();it++){
        if(!visited[*it]){
            
            dfs(visited,*it);
        }
    }
    
}

void kosaraju(){
    vector<int>visited(V,0);
    stack<int>stk;
    for(int i =0;i<V;i++){
        if(!visited[i]){
            dfsStk(visited,i,stk);
        }
    }
    for(int i =0;i<V;i++)visited[i]=0;
    // transpose;
    for(int u =0;u<V;u++){
         for(vector<int>::iterator it = adj[u].begin();it!=adj[u].end();it++){
            adjRev[*it].push_back(u); 
         }
    }
    while(!stk.empty()){
        int u =stk.top();stk.pop();
        if(!visited[u]){
            dfs(visited,u);
        }
        cout<<endl;
    }

}


int main(){
    return 0;
}