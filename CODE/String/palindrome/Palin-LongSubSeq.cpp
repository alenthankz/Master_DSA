#include<bits/stdc++.h>
using namespace std;
// length of the longestPalindromicSubSeq
int longestPalindromicSubSeq(string  str){
    int n =str.size();
    vector< vector<int> >dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    for(int gap =2;gap<=n;gap++){
        for(int i=0;i<n-gap+1;i++){
            int j =i+gap-1;
            if(str[i]==str[j] && gap ==2)
                dp[i][j]=2;
            else if(str[i]==str[j])
                dp[i][j]=dp[i+1][j-1]+2;
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]); //this step is not needed for substring
            }
        }
    }
    
    return dp[0][n-1];
}


int main(){
    string str ="malayalam";
    cout<<longestPalindromicSubSeq( str)<<endl;
    return 0;
}