/*
you are given a tree consisting of n vertices. A tree is a connected undirected graph with n−1 edges. Each vertex v 
of this tree has a color assigned to it (av=1 if the vertex v is white and 0 if the vertex v is black).
You have to solve the following problem for each vertex v: what is the maximum difference between the
number of white and the number of black vertices you can obtain if you choose some subtree of the given 
tree that contains the vertex v? The subtree of the tree is the connected subgraph of the given tree. More formally,
if you choose the subtree that contains cntw white vertices and cntb black vertices, you have to maximize cntw−cntb.
*/


#include<bits/stdc++.h>
using namespace std;
#define loop1(i,N) for(int i =1;i<N;i++)
#define loop(i,N) for(int i =0;i<N;i++)

int treeTravs(vector< vector<int> >&arr,int i,vector<int>&color,vector<int>&dp){
    if(arr[i].size()==0){
        dp[i]=color[i];
        return color[i];
    }
    // cout<<i<<" ";
    int res=INT_MIN;
    if(dp[i]!=INT_MIN)return dp[i];
    for(vector<int>::iterator it =arr[i].begin();it!=arr[i].end();it++){
        int ans=treeTravs(arr,*it,color,dp);
        int m = max( color[i], max(ans,color[i]+ans));
        if(m>res){
           res=m;
        }
    }
    // cout<<endl;
    dp[i]=res;
    return res;
}

int main(){
    int N;
    cin>>N;
    vector< vector<int> >arr(N+1);
    vector<int>color(N+1,-1);
    loop1(i,N+1){
        int t;
        cin>>t;
        if(t){
            color[i]=1;
        }
    }
    loop(i,N-1){
        int a, b;
        cin>>a;cin>>b;
        arr[a].push_back(b);
        // arr[b].push_back(a);
    }
    vector<int>dp(N+1,INT_MIN);
    treeTravs(arr,1,color,dp);
    loop1(i,N+1){
        cout<<dp[i]<<" ";
    }
    return 0;
}