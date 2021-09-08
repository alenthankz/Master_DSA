#include<bits/stdc++.h>
using namespace std;
#define V 10
list< pair<int,int> > * adj =new list< pair<int,int> >[V];

vector<int>burnt(V,0);
vector<int>dist(V,INT_MAX);
int getmin(){
    int ind =0;
    int mi =INT_MAX;
    for(int i =0;i<V;i++){
        if(!burnt[i] && dist[i]<mi){
            mi =dist[i];
            ind =i;
        }
    }
    return ind;
}
void dijsra(int src){
    dist[src]=0;
    for(int i =0;i<V;i++){
        int v =getmin();
        burnt[v]=1;
        for( list< pair<int,int> >::iterator it =adj[v].begin();it!=adj[v].end();it++ ){
            if(!burnt[it->first] && dist[it->first]>dist[v]+it->second )
                dist[it->first]=dist[v]+it->second;
                // minHere = min(minEdge[v],it.second)
                // if(dist[it.first]==dist[v]+(it.second ) ){
                //     minEdge[it.first]=min(minEdge[it.first], minHere);
                // }else{
                //     dist[it.first]=dist[v]+(it.second );
                //     minEdge[it.first]=minHere;
                // }
        }
    }
     for(int i =0;i<V;i++){
            cout<<dist[i]<<" ";
    }
    cout<<endl;
}
int main(){

    adj[0].push_back(make_pair(1, 4));
    adj[0].push_back(make_pair(7, 8));
    adj[1].push_back(make_pair(2, 8));
    adj[1].push_back(make_pair(7, 11));
    adj[2].push_back(make_pair(3,7));
    adj[2].push_back(make_pair(8,2));
    adj[2].push_back(make_pair(5,4));
    adj[3].push_back(make_pair(4,9));
    adj[3].push_back(make_pair(5,14));
    adj[4].push_back(make_pair(5,10));
    adj[5].push_back(make_pair(6,2));
    adj[6].push_back(make_pair(7,1));
    adj[6].push_back(make_pair(8,6));
    adj[7].push_back(make_pair(8,7));
   
    // for(int i =0;i<V;i++){
    //     cout<<i<<": ";
    //     for( list< pair<int,int> >::iterator it =adj[i].begin();it!=adj[i].end();it++ ){
    //         cout<<"["<<it->first<<","<<it->second<<"],";
    //     }
    //     cout<<endl;
    // }
     dijsra(0);
    return 0;
}