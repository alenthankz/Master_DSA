#include<bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};
int myComp(struct val&a ,struct val&b){
    return a.second<b.second;
}

int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,myComp);
    vector<int>dp(n,1);
    int maax=1;
    dp[0]=1;
    for(int i =1;i<n;i++){
        dp[i]=1;
        for(int j =0;j<i;j++){
            int subRes=1+dp[j];
            if(p[i].first>p[j].second &&dp[i]<subRes){
                dp[i]=subRes;
            }
        }
        maax = max( maax , dp[i]);
    }
    return maax;
}