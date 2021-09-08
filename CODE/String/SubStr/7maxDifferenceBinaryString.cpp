//substring with maximum difference (no of 0 - no of 1)
// we will be using kadanes algorithm
//covert 0 to 1 && 1 to -1
#include<bits/stdc++.h>
using namespace std;

int maxDifference(string str){
    int n =str.size();
    vector<int>arr(n,-1);
    for(int i =0;i<n;i++){
        if(str[i]=='0')arr[i]=1;
    }
    int sum =0, st=0,maxSum=0;
    for(int i =0;i<n;i++){
        sum+=arr[i];
        if(sum<0){sum=0,st=i+1;}
        maxSum = max(maxSum,sum);
    }
    return maxSum;
}

int main(){

    return 0;
}