// pattern search in a grid

#include<bits/stdc++.h>
using namespace std;
#define R 3 
#define C 14 

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

bool travs(char grid[R][C],int i,int j,string pat){
    if(grid[i][j]!=pat[0])return false;
    int len =pat.size();
    for(int dir =0;dir<8;dir++){
        int x=i+dx[dir];int y =j+dy[dir];
        int l;
        for(l=1;l<len;l++){
            if(x>=R || y>=C ||x<0 || y<0)break;
            if(pat[l]!=grid[x][y])break;
            x+=dx[dir];y+=dy[dir];
        }
        if(l==len)return true;
    }
    return false;
}

void patternSearch(char grid[][C],string pat){
    for(int i =0;i<R;i++){
        for(int j =0;j<C;j++){
            if(travs(grid,i,j,pat)){
                cout<<"word @ :"<<i<<" "<<j<<endl;
            }
        }
    }
}


int main(){
    char grid[R][C] = { "GEEKSFORGEEKS", 
                        "GEEKSQUIZGEEK", 
                        "IDEQAPRACTICE"
                       }; 
    patternSearch(grid,"GEEKS");
    return 0;
}