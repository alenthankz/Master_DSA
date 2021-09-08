// In a maze somepaths are blocked no of ways of traversal till the end;
// motion restricted to right and down.      '#' represent block
#include<bits/stdc++.h>
using namespace std;


int main(){ 
    char mat[5][2]={
        {'.','.'},
        {'.','.'},
        {'.','.'},
        {'#','.'},
        {'.','.'}
    };

    vector< vector<int> >dp(5,vector<int>(2,0));

    for(int i =0;i<5;i++){
        if(mat[i][0]=='#')break;
        else dp[i][0]=1;
    }
    for(int i =0;i<2;i++){
        if(mat[0][i]=='#')break;
        else dp[0][i]=1;
    }

    for(int i=1;i<5;i++){
        for(int j=1;j<2;j++){
            if(mat[i][j]!='#')
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            else 
                dp[i][j]=0;
        }
    }
    for(int  i=0;i<5;i++){
        for(int j=0;j<2;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[4][1];
    return 0;
}