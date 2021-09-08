#include<bits/stdc++.h>
using namespace std;
int findMinRec(int * arr,int n,int sum1,int sum_total){
    if(n==0)return abs((sum_total-sum1)-sum1);
    return min( findMinRec(arr,n-1,sum1+arr[n-1],sum_total),findMinRec(arr,n-1,sum1,sum_total));
}
int findMin(int * arr,int n){
    int sum =0;
    for(int i =0;i<n;i++){
        sum+=arr[i];
    }
    vector< vector<bool> >dp(n+1,vector<bool>(sum+1,false));

    for(int i =0;i<n+1;i++){
        for(int j =0;j<sum+1;j++){
            if(j==0)dp[i][j]=true;
            else if(i==0)dp[i][j]=false;
            else if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    
    int k;
    for(k =sum/2;k>=0;k--){
        if(dp[n][k]){
            break;
        }
    }

    return sum - (2*k);
}

int main(){
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The minimum difference between 2 sets is "
         << findMin(arr, n);
    return 0;
}