// back track is nothing but dfs but we want to save the combination of the dfs that gave us ans , thats all.
// after this check out Nqueen problem in dfs
#include<bits/stdc++.h>
using namespace std;
#define N 8
typedef vector< vector<int> > VVI;

void printBoard(VVI& board){
    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
int isSafe(int x, int y,VVI& board )
{
    return (x >= 0 && x < N && y >= 0 && y < N
            && board[x][y] == -1);
}
int solveKnightUtil(int x , int y ,int mov , VVI& board , int *xMove,int*yMove ){
    int k, next_x,next_y;
    if(mov==N*N)return 1;
    for(k =0;k<8;k++){

        next_x = x + xMove[k];
        next_y = y + yMove[k];

        if (isSafe(next_x, next_y, board)) {
            board[next_x][next_y] = mov;
            if (solveKnightUtil(next_x, next_y, mov + 1, board,xMove, yMove)== 1)return 1;
            board[next_x][next_y] = -1;
        }
        
    }
    return 0;
}


int solveKnight(){
    VVI board(N, vector<int>(N,-1));
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    board[0][0]=0;
    if(solveKnightUtil(0,0,1,board,xMove,yMove)==0){cout<<"NO solution"; return 0;}
    else{
        printBoard(board);
    }
    return 1;
}
int main(){
    solveKnight();
    return 0;
}