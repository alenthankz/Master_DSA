#include<bits/stdc++.h>
using namespace std;

int lcsRecur(string str1,int n,string str2,int m){
    if(n==0 || m==0)return 0;
    if(str1[n-1]==str2[m-1]) return 1+lcsRecur(str1,n-1,str2,m-1);
    else return max(lcsRecur(str1,n-1,str2,m),lcsRecur(str1,n,str2,m-1));
}

int lcsDp(string str1 ,int n,string str2,int m){
    vector< vector<int> >dp(n+1,vector<int>(m+1,0));

    for(int i =0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i ==0 || j==0)
                dp[i][j]=0; 
            else if(str1[i-1]==str2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]= max(dp[i][j-1],dp[i-1][j]);           
        }
    }
    // for(int i =0;i<n+1;i++){
    //     for(int j=0;j<m+1;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int len = dp[n][m];
    cout<<len<<endl;
    int i=n,j =m;
    char str[len+1];
    str[len]='\0';
    len--;
    while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            str[len]=str1[i-1];
            len--;i--;j--;
        }
        else if (dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<str<<endl;
     
}

int main(){
    // here there is no specific order for the strings,str1 subseq of str2 or vice versa
    string str1 ="AGGTAB",str2="GXTXAYB";
    int n =str1.size(),m =str2.size();
    cout<<lcsRecur(str1,n,str2,m)<<endl;
    cout<<lcsDp(str1,n,str2,m);
    return 0;
}