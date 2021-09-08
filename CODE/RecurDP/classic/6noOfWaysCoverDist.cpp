// no of ways to cover a dist froma given set on numbers
#include<bits/stdc++.h>
using namespace std;

//order matters here that for eg dist 4 from {1,2,3} => 1,2,1 && 2,1,1 are differnt
int noOfWays(int *arr,int n,int sum,vector<int>&dp){
    if(sum==0)return 1;
    int res=0;
    for(int i =0;i<n;i++){
        if(sum>=arr[i]){
           int subRes=noOfWays(arr,n,sum-arr[i],dp);
           res+=subRes;
        }
    }
    return res;
}

int noOfwaysCoverDistDp(int arr[],int n ,int k){
    int dp[k+1]={0};
    dp[0]=1;

    for(int i =1;i<=k;i++){
        for(int j =0;j<n;j++){
            if(i>=arr[j]){
                int subRes=dp[i-arr[j]];
                dp[i]+=subRes;
            }
        }
    }
    return dp[n];
}

int main(){
    int arr[]={1,2,3};
    int sum =4;
    vector<int>dp(sum+1,0);
    int n =sizeof(arr)/sizeof(arr[0]);
    cout<<noOfWays(arr,n,sum,dp)<<endl;

}