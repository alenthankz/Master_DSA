// this question cna be done using bfs also 
// question is to find the number of ways to fill n gaps using m values,such that the order of values is increasing. 
// eg: n =4 , values:m: 4 = 1,2,3,4    =>   1,1,1,1 | 1,1,1,2 | 1 2 2 2 | 1 2 3 4 but not 1 2 1 3 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 4;
    int m =4;
    int values[4]={8,9,10,11};//here values really doesnt matter as it is count we require
    vector< vector<int> >dp(n, vector<int>(m,1));
    for(int i =0;i<m;i++){
        dp[0][i]=i+1;
    }
    for(int i =1;i<n;i++){
        for(int j =1;j<m;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[n-1][m-1];

    return 0;
}