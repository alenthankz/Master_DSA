// this is so similar to palindrome cause they both are based on last and first ele of a arr/string

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;


int F(int arr[] , int i , int j ){
    if(i==j)return arr[i];
    return max (
        arr[i] + min( F(arr,i+2,j), F(arr,i+1,j-1)) ,
        arr[j] + min( F(arr,i,j-2), F(arr,i+1,j-1)) 
    );
}


void Fdp(int *arr ,int n){
    int i =0 , j =n-1;
    VVI dp(n , VI(n,0));
    for(int i =0;i<n;i++)dp[i][i]=arr[i];

    for(int gap=2;gap<=n;gap++){
        for(int i =0;i<n-gap+1;i++){
            int j =i+gap-1;
            if(gap==2){
                dp[i][j]=max(arr[i],arr[j]);
            }
            else{
                dp[i][j]=max(
                    arr[i]+min(dp[i+1][j-1],dp[i+2][j]),
                    arr[j]+min(dp[i+1][j-1],dp[i][j-2])
                );
            }
        }
    }
}

int main(){
    
    return 0;
}