#include<bits/stdc++.h>
using namespace std;
void lcs(string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    vector< vector<int> >dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j =1;j<=m;j++){
           
                if(str1[i-1]==str2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);  //dp[i][j]=0 for lcSubstring & ans= max(...dp)
            
        }
    }
   
    int len =dp[n][m];
    cout<<len<<endl;
    char res[len+1];
    res[len]='\0';
    int i =n,j=m;
    while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            len--;
            res[len]=str1[i-1];
            i--;j--;
        }
        else if(dp[i][j-1]>dp[i-1][j])j--;
        else i--;
    }
    cout<<res<<endl;
}
int main(){
    string str1 ="AGGTAB",str2="GXTXAYB";
    lcs(str1,str2);
    return 0;
}