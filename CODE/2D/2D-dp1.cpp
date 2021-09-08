// problem : maximum length snake sequence
// A snake sequence is made up of adjacent numbers in the grid such that for each number, 
// the number on the right or the number below it is +1 or -1 its value
#include<bits/stdc++.h>
using namespace std;


void printSnakeSeq(int mat[][4],int i,int j,vector<vector<int> >&dp){
    stack<pair<int,int> >s;
    s.push(make_pair(i,j));
    while(dp[i][j]!=1){
        if(dp[i-1][j] == dp[i][j]-1 && i>0){
            
            s.push(make_pair(i-1,j));
            i--;
        }
        else if(dp[i][j-1] == dp[i][j]-1 && j>0){
           
            s.push(make_pair(i,j-1));
             j--;
        }
    }
    
    while(!s.empty()){
        cout<<s.top().first<<" "<<s.top().second<<" :"<<mat[s.top().first][s.top().second]<<endl;
        s.pop();
    }
}

void findSnakeSeq(int mat[][4]){
    
    vector< vector<int> >dp(4,vector<int>(4,0));
    dp[0][0]=1;
    int max_len =0;
    int endi =0,endj=0;

    for(int i=0;i<4;i++){
        for(int j =0;j<4;j++){

            if(!i && !j)continue;
            if(abs(mat[i-1][j]-mat[i][j]) && i>0){
                dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
                if(dp[i][j]>max_len){
                    max_len =dp[i][j];
                    endi=i;endj=j;
                }
            }
            if(abs(mat[i][j-1]-mat[i][j]) && j>0){
                dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
                if(dp[i][j]>max_len){
                    max_len =dp[i][j];
                    endi=i;endj=j;
                }
            }

        }
    }

    cout<<max_len<<endl;
    printSnakeSeq(mat,endi,endj,dp);
}



int main(){

     int mat[4][4]={
        {9,6,5,2},
        {8,7,6,5},
        {7,3,1,6},
        {1,1,1,7}
    };

    findSnakeSeq(mat);

    return 0;
}