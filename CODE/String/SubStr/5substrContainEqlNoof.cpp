// 1) substring containing equal no of 0 ,1 ,2s
// 2) substrings containing equal no of lowercase and uppercase

#include<bits/stdc++.h>
using namespace std;

// S = "gEEk" Output: 3 "gE", "gEEk" and "Ek"
// S = "WomensDAY" Output: 4 "Wo", "ensDAY", "nsDA" and "sD"
// The general Idea here is : for i , j => countLower(str[i-j])=countUpper(str[i-j])
// countLower(str[i])-countLower(str[j-1]) == countUpper(str[i])-countUpper(str[j-1]) =>
// countLower(str[i])-countUpper(str[i])   == countUpper(str[j-1])-countLower(str[j-1])
// build a hash map for countLower(str[i])-countUpper(str[i]) and check if it already exist in hash
int F2(string str){
    map<int,int>mp;
    int cntL=0,cntU=0;
    int ans=0;
    mp[0]=1;
    for(int i =0;i<str.size();i++){
        if(islower(str[i]))cntL++;
        else cntU++;
        int diff = cntL-cntU;
        ans+=mp[diff];
        mp[diff]++;
    }
    return ans;
}

int F1(string str){
    int n = str.length();
    map< pair<int, int>, int > mp;
    int zc = 0, oc = 0, tc = 0;

    int res = 0;  
    mp[make_pair(0, 0)] = 1;
    
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == '0') zc++;
        else if (str[i] == '1') oc++;
        else tc++;

        pair<int, int> tmp = make_pair(zc - oc,zc - tc);
        res += mp[tmp];
        mp[tmp]++;
    }
    return res;
}

int main(){
    return 0;
}