//minimum no of nodes needed to reach al the nodes in a dag
//it is just to find the vertices that have the indegree 0
//if the question i would suggerst to think about dag

#include<bits/stdc++.h>
using namespace std;

int minNoOfVertices(vector< vector<int> >adj ,int V){
    vector<int>indegree(V,0);
    for(int i =0;i<V;i++){
        for(vector<int>::iterator it=adj[i].begin();it!=adj[i].end();it++){
            indegree[*it]++;
        }
    }
    int count=0;
    for(int i =0;i<V;i++){
        if(indegree[i]==0)count++;
    }
    return count;
}

int main(){
    return 0;
}