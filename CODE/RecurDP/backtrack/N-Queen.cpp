#include<bits/stdc++.h>
using namespace std;

#define N 4
bool isSafe(int board[N][N],int row,int col){

    for(int i =0;i<col;i++){
        if(board[row][i]==1)return false;
    }

    //left Upper diagonal 

    for(int i =0,j=0;i<=row && j<=col;i++,j++){
        if(board[i][j]==1)return false;
    }

    for(int i =row,j=col;i<N && j>=0;i++,j--){
        if(board[i][j]==1)return false;
    }

    return true;
}

bool solveNQUtil(int board[N][N],int col){
    // for a col try to place it in some row
    // we are keepfilling col one by one.
    if(col>=N)return true;
    for(int i =0;i<N;i++){
        if(isSafe(board,i,col)){
            board[i][col]=1;
            if(solveNQUtil(board,col+1))return true;
            board[i][col]=0;
        }
    }
}

void nQueen(){
    int board[N][N] = { { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 } }; 
  
    if (solveNQUtil(board, 0) == false) { 
        printf("Solution does not exist"); 
    }else
    cout<<"yes";
    
}

int main(){
    nQueen();
    return 0;
}