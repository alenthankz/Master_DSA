#include<bits/stdc++.h>
using namespace std;
#define C 4
#define R 4
#define N 4
void rotate(int mat[][C]){
    int m =R,n =C,row=0,col=0;
    int prev=0;
    int curr=0;
    while(row<m && col<n){

        if(row+1 ==m || col+1==n)break;
        prev =mat[row+1][col];

        for(int i =col;i<n;i++){
            curr =mat[row][i];
            mat[row][i]=prev;
            prev =curr;
        }
        row++;

        for(int i =row;i<m;i++){
            curr =mat[i][n-1];
            mat[i][n-1]=prev;
            prev=curr;
        }
        n--;
        if(row<m){
                for(int i =n-1;i>=col;i--){
                    curr =mat[m-1][i];
                    mat[m-1][i]=prev;
                    prev=curr;
                }
        }
        m--;
        if(col<n){
                for(int i =m-1;i>=0;i--){
                    curr =mat[i][col];
                    mat[i][col]=prev;
                    prev=curr;
                }
        }
        col++;
    }

    for(int i =0;i<R;i++){
        for(int j =0;j<C;j++){
            cout<<mat[i][j]<<"   ";
        }
        cout<<endl;
    }
}



void alternate(int mat[N][N]){
    for(int x =0;x<N/2;x++){
        for(int y=x;y<N-x-1;y++){
            int temp =mat[x][y];
            mat[x][y]=mat[y][N-x-1];
            mat[y][N-x-1]=mat[N-x-1][N-y-1];
            mat[N-x-1][N-y-1]=mat[N-y-1][x];
            mat[N-y-1][x]=temp;
        }
    }
}

int main(){
    int mat[N][N] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
        
    for(int i =0;i<2;i++){        
        rotate(mat);
        cout<<endl;}
    
  
    return 0;
}