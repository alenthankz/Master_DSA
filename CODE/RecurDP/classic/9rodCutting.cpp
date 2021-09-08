#include<bits/stdc++.h>
using namespace std;

//ordered repeating
int maxCut(int prices[],int n){
    if(n==0)return 0;
    int res =INT_MIN;
    for(int i =0;i<n;i++){
        int subRes = prices[i]+maxCut(prices,n-(i+1));
        if(subRes>res)res=subRes;
    }
    return res;
}

int maxCutDp(int prices[],int n){
    int dp[n+1]={INT_MIN};
    dp[0]=0;

    for(int i =1;i<=n;i++){
        for(int j =0;j<i;j++){
            int subRes=prices[j]+dp[i-(j+1)];
            if(subRes>dp[i])dp[i]=subRes;
        }
    }
    return dp[n];
}

int main(){
    
    return 0;
}