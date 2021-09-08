#include<bits/stdc++.h>
using namespace std;

// order doesnt matterhere that for a 4rs coin from {1rs,2rs,3rs} => 1+2+1 = 2+1+1
int noofWaysCoinChangeRecur(int arr[],int n,int k){
    if(k==0)return 1;
    if(n==0)return 0;
    if(k<arr[n-1])return noofWaysCoinChangeRecur(arr,n-1,k);
   return noofWaysCoinChangeRecur(arr,n-1,k) + noofWaysCoinChangeRecur(arr,n,k-arr[n-1]);
}

int noofWaysCoinChangeDp(int arr[] ,int n ,int k){
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));

    for(int i =0;i<=n;i++){
        for(int j =0;j<=k;j++){
            if(j==0)dp[i][j]=1;
            else if(i==0)dp[i][j]=0;
            else if(j>=arr[i-1])dp[i][j]=dp[i][arr[j-arr[i-1]]]+dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }
}

int main(){
    
    return 0;
}