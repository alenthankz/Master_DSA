// can do only atmost k transactions

#include<bits/stdc++.h>
using namespace std;

int maxProfit(int price[] ,int n ,int k){
    vector< vector<int> > dp( k+1 ,vector<int>(n,0) );

    for(int i =1;i<k+1;i++){
        for(int j =1;j<n;j++){
            dp[i][j]=dp[i][j-1]; //not doing any transation at day j;
            //selling at day j , buying at day m<j
            for(int m=0;m<j;m++){
                dp[i][j]=max ( dp[i][j] , (price[j]-price[m]+dp[i-1][m] ) );
            }
        }
    }
}

int main(){
    return 0;
}