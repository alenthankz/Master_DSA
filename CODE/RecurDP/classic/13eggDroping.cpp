#include<bits/stdc++.h>
using namespace std;

int eggDropRec(int n,int k){
    if(k==0 ||k==1)return k;
    if(n==1)return k;
    int ans =INT_MAX;
    for(int x =1;x<=k;x++){
        int res =max(eggDropRec(n-1,x-1),eggDropRec(n,k-x));
        if(res<ans){
            ans=res;
        }
    }
    return ans+1;
}

int eggDropDp(int n,int k){
    vector< vector<int> >dp(n+1,vector<int>(k+1,0));
    for(int i =0;i<=n;i++){
        dp[i][0]=0;
        dp[i][1]=1;
    } 
    for(int i=1;i<=k;i++){
        dp[1][i]=i;
    }
    for(int i =2;i<=n;i++){
        for(int j =2;j<=k;j++){
             dp[i][j]=INT_MAX;
            for(int x=1;x<=j;x++){
                int res =1+max(dp[i-1][x-1],dp[i][j-x]);
                if(res<dp[i][j]){
                    dp[i][j]=res;
                }
            }
        }
    }
    return dp[n][k];
}

int main(){
    int n = 2, k = 10; 
    cout<<eggDropRec(n,k)<<endl;
    cout<<eggDropDp(n,k)<<endl;
    return 0;
}