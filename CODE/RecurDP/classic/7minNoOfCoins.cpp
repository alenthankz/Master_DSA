#include<bits/stdc++.h>
using namespace std;

//minimum no of coins required to make k , as it is minimum we can use ordered or undoreder ,
// here we go with ordered and repeating.

int minNoCoinsReqRecur(int arr[],int n ,int k){
    if(k==0)return 0;
    int res=INT_MAX;
    for(int i =0;i<n;i++){
        
        if(arr[i]<=k){
             int subRes= minNoCoinsReqRecur(arr,n,k-arr[i]);
             if(subRes!=INT_MAX && res>subRes)res=subRes+1;
        }
        
    }
    return res;
}

int minNoCoinsReqDp(int arr[],int n ,int k){
    int dp[k+1]={INT_MAX};
    dp[0]=0;

    for(int i =1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(arr[j]<=i){
                int subRes=dp[i-arr[j]];
                if(subRes!=INT_MAX && dp[i]>subRes)dp[i]=1+subRes;
            }
        }
    }

    return dp[n];
}

int main(){
    
    return 0;
}