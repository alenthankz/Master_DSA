// dp goes well with DFS.

// here the problem is cleanrbt in spoj
// we have some dirty tiles and some blocked ways , our question is to find the min no of moves from intial 
// point to clean all the dirty tiles.

// APPROACH:
// first calulate bfs (shortest distance) from each dirty tile meaning 
// we will have a 2D array such that at ith row we have minimum distance to all other tiles from ith tile 
// then it is essentially traveslling salesman problem (tsp) we can do it with bit dp;

#include<bits/stdc++.h>
using namespace std;
#define N 10
int dist[N][N];
// mask is usually 11111....
// instead of visited

int tsp(int src ,int mask ,int n){
    if(!mask)return 0;
    int res=INT_MAX;
    for(int i=0;i<n;i++){
        if( mask&(1<<i) ){
            int subRes= dist[src][i]+ tsp(i,mask^(1<<i),n); 
            if(subRes<res)res=subRes;
        }
    }
    return res;
}

int main(){

    return 0;
}