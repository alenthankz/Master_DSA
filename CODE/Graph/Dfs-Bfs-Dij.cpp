#include<bits/stdc++.h>
using namespace std;
#define V 10

list<int> *adj =new list<int>[V];


int visitedD[V]={0};
void dfs(int v,int * parent){
    visitedD[v]=1;
    for(list<int>:: iterator it =adj[v].begin();it!=adj[v].end();it++){
        if(visitedD[*it]!=1){
            parent[*it]=v;
            dfs(*it,parent);
        }
    }
}

int visitedB[V]={0};
void bfs(int v){
    visitedB[v]=1;
    queue<int>q;q.push(v);
    while(!q.empty()){
        v =q.front();q.pop();
        if(list<int>:: iterator it =adj[v].begin();it!=adj[v].end();it++){
            if(visitedB[*it]!=1){
                visitedB[*it]=1;
                q.push(*it);
            }
        }
    }
}






int main(){
    
    return 0;
}