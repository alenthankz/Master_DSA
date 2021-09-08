#include<bits/stdc++.h>
using namespace std;
#define M 5
#define N 5
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int isSafe(int matrix[N][M],int l ,int k){
    if(l<N && k<M && l>=0 && k>=0)return true;
    return  false;
}
void dfs(int matrix[N][M ], int l ,int k){
    matrix[l][k]=0;
    for(int i =0;i<8;i++){
        int lnew = l+dx[i], knew=k+dy[i];
        if(isSafe(matrix,lnew,knew) && matrix[lnew][knew]){
            dfs(matrix,lnew,knew);
        }
    }
}
int main(){
    int matrix[N][M];
    int count =0;
    for(int i =0;i<N;i++){
        for(int j =0;j<M;j++){
            if(matrix[i][j]){
                dfs(matrix,i,j);count++;
            }
        }
    }
    return 0;
}