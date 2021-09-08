#include<bits/stdc++.h>
using namespace std;
// remeber to use define for row and col next time.
int dirx[8]={ -1, -1, -1, 0, 0, 1, 1, 1 }; 
int diry[8]={ -1, 0, 1, -1, 1, -1, 0, 1 };

bool isSafe(int i ,int j){
    if(i<0 || j<0 || i>=5 || j>=5)return false; //imp REMEBER FOR 2D
    return true;
}
void dfs(int mat[][5],int i,int j){ //be careful when arugements are taken i & j , remeber not to give local variabales again i/j;
    mat[i][j]=0;
    for(int k =0;k<8;k++){
        if(isSafe(i+dirx[k],j+diry[k])  && mat[i+dirx[k]][j+diry[k]]==1){
            dfs(mat,i+dirx[k],j+diry[k]);
        }
    }
}

int find_first(int mat[][5]){
    vector< vector<int> > visited (5, vector<int>(5,0));
    int cnt=0;
    for(int i =0;i<5;i++){
        for(int j =0;j<5;j++){
            if(mat[i][j]==1 ){
                dfs(mat,i,j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int mat[][5] ={{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1}};
    
    cout<<find_first(mat);
    return 0;
}