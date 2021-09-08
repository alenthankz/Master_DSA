#include<bits/stdc++.h>
using namespace std;
/*
Given two integers N and K, the task is to find all valid combinations of K numbers 
that adds up to N based on the following conditions:

Only numbers from the range [1, 9] used.
Each number can only be used at most once.

Input: N = 7, K = 3
Output: 1 2 4
Explanation: The only possible combination is of the numbers {1, 2, 4}.

Input: N = 9, K = 3
Output: 
1 2 6
1 3 5
2 3 4
*/

void backtrack(int sum , int k , int st , vector<int>&ans){
    if(sum==0 && k==0){
        for(int i =0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(sum<=0 || k<=0)return ;

    for(int i=st+1;i<=9;i++){
        if(sum>=i){
            ans.push_back(i);
            backtrack(sum-i,k-1,i,ans);
            ans.pop_back();
        }
    }
}
int main(){
    int arr[]={1,2,3};
    int sum=5;
    vector<int>ans;
    backtrack(9,3,0,ans);
    return 0;
}