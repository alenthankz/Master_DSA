#include<bits/stdc++.h>
using namespace std;

bool isSubseqRec(string str1,int n,string str2,int m){
    if((n ==0 && m==0) || m==0)return true;
    if(n==0) return false;
    if(str1[n-1]==str2[m-1]) return isSubseqRec(str1,n-1,str2,m-1);
    else return isSubseqRec(str1,n-1,str2,m);
}
bool isSubseqIter(string str1,int n,string str2,int m){
    int j =0;
    for(int i =0;i<n;i++){
        if(str2[j]==str1[i]){
            j++;
            if(j==m)return true;
        }
    }
    return false;
}

int countSubSeqRec(string str1,int n,string str2,int m){
    if(m==0)return 1;
    if(n==0)return 0;

    if(str1[n-1]==str2[m-1])return  countSubSeqRec(str1,n-1,str2,m-1)+countSubSeqRec(str1,n-1,str2,m);
    else  return countSubSeqRec(str1,n-1,str2,m);
}

int countSubSeqIterDP(string str1,int n,string str2,int m){
    // the idea here is very important. We take i lenth str1 and j length str2 . use the recursive idea
    // i,e if last of both are same we either include or discard. 
    vector< vector<int> >dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            else 
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][m];
}


int main(){
    // here we are checking specifically if str2 is subseq of str1 and its counts
    string str1="GeeksforGeeks",str2="Gks";
    int n =str1.size(),m=str2.size();
    cout<<isSubseqRec(str1,n,str2,m)<<endl;
    cout<<isSubseqIter(str1,n,str2,m)<<endl;

    cout<<countSubSeqRec(str1,n,str2,m)<<endl;
    cout<<countSubSeqIterDP(str1,n,str2,m)<<endl;

    return 0;
}