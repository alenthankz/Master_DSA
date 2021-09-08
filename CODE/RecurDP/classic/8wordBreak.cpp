#include<bits/stdc++.h>
using namespace std;

int dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false;
}

bool wordBreak(string str,int n ,vector<int>&dp){
    if(n==0)return true;
    if(dp[n]!=-1)return dp[n];
    dp[n]=0;
    for(int i =n-1;i>=0;i--){
        bool subRes = dictionaryContains( str.substr(i,n-i)   ) && wordBreak(str,i,dp);
        dp[n]=dp[n]||subRes;
        if(dp[n])return 1;
    }
    return dp[n];
}



int main(){
    string str="samsungandmango";
    int n =str.size();
    vector<int>dp(n+1,-1);

    cout<<wordBreak(str,n,dp);
    return 0;
}
