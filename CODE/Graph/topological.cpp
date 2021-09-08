#include<bits/stdc++.h>
using namespace std;
#define V 10
list<int> * adj =new list<int>[V];

void topological(){
    vector<int>indegree(V,0);
    for(int i =0;i<V;i++){
        for(list<int>::iterator it =adj[i].begin();it!=adj[i].end();it++){
            indegree[*it]++;
        }
    }
    stack<int>stk;
    for(int i =0;i<V;i++){
        if(indegree[i]==0)stk.push(i);
    }
    vector<int>Lpath(V,0);
    while(!stk.empty()){
        int v =stk.top();stk.pop();
        for(list<int>::iterator it =adj[v].begin();it!=adj[v].end();it++){
            indegree[*it]--;
            Lpath[*it]=max(Lpath[*it],Lpath[v]+1);
            if(!indegree[*it])stk.push(*it);
        }
    }
}
int main(){
    return 0;
}