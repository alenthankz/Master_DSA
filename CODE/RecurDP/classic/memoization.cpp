#include<bits/stdc++.h>
using namespace std;

int minimizeOperationsBottomUp(int now,int final , vector<int>&dp){
    if(now>final)return (INT_MAX-1);
    if(now==final)return 0;
    if(dp[now]!=-1)return dp[now];
    dp[now]= min(1+minimizeOperationsBottomUp(now+1,final,dp), 1+minimizeOperationsBottomUp(now*2,final,dp) );
    return dp[now];
}

int minimizeOperationsTopDown(int final , vector<int>&dp){
    if(final<1)return (INT_MAX-1);
    if(final==1)return 0;
    if(dp[final]!=-1)return dp[final];
    if(( final/2)*2!=final) dp[final]=1+minimizeOperationsTopDown(final-1,dp);
    else dp[final]= min(1+minimizeOperationsTopDown(final-1,dp), 1+minimizeOperationsTopDown(final/2,dp) );
    return dp[final];
}

int main(){
    int now=1,final=10;
    vector<int>dp(11,-1);

    return 0;
}
