#include<bits/stdc++.h>
using namespace std;

int min(int x,int y,int z){
    return min(min(x,y),z);
}

int editDist(int n,int m,string str1,string str2)
{
    if(n==0)return m;
    if(m==0)return n;
    if(str1[n-1]==str2[m-1]) return editDist(n-1,m-1,str1,str2);
    else 
     return 1+min(editDist(n,m-1,str1,str2),
                editDist(n-1,m,str1,str2),
                editDist(n-1,m-1,str1,str2));
}

int editDistDP(string str1,string str2){
    int n =str1.size();
    int m =str2.size();
    vector< vector<int> >dp(n+1,vector<int>(m+1,0));
    for(int i =0;i<=n;i++){
        for(int j =0;j<=m;j++){
            if(i==0)dp[i][j]=j;
            else if(j==0)dp[i][j]=i;
            else if(str1[i-1]==str2[j-1])dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
        }
    }
    return dp[n][m];
}
int main(){
    string str1 = "sunday";
    string str2 = "saturday";
 
    cout << editDistDP(str1, str2);
    return 0;
}