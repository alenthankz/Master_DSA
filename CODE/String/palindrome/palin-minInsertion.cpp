#include<bits/stdc++.h>
using namespace std;

// min insertion irrespective of postition

int main(){
    string str ="alen";
    int n =str.size();
    vector< vector<int> >dp(n,vector<int>(n,0));

    for(int gap =2;gap<=n;gap++){
        for(int i=0;i<n-gap+1;i++){
            int j =i+gap-1;
            if(str[i]==str[j])
                dp[i][j]=dp[i+1][j-1];
            else 
                dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1; //<-MIN not max
        }
    }
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[0][n-1];
    return 0;
}