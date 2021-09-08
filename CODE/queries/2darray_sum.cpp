// here 2d array is immutable

// (l2,r2) - (l2,r1-1) -(l1-1,r2) + (l1-1,r1-1)

#include<bits/stdc++.h>
using namespace std;
typedef vector< vector<int> > Vii;
#define loop(i,n) for(int i =0;i<n;i++)
int main(){
    int n =4;
    Vii mat (n,vector<int>(n,0));
    Vii dp  (n+1, vector<int> (n+1,0));

    loop(i,n){
        loop(j,n){
            if( i ==0 || j==0 )continue;
            dp[i][j]=dp[i-1][j]+dp[i][j-1] -dp[i-1][j-1] + mat[i-1][j-1];
        }
    }
    int l2=2,r2=3;
    int l1=0,r1=1;
    int ans = dp[l2+1][r2+1]-dp[l2+1][r1] -dp[l1][r2+1] +dp[l1][r1];
    return 0;
}