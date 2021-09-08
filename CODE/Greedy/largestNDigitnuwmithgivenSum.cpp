#include<bits/stdc++.h>
using namespace std;

int fn(int N,int sum){
    vector<int>arr(N,0);

    for(int i =0;i<N;i++){
        if(sum>=9){
            arr[i]=9;
            sum-=9;
        }else{
            arr[i]=sum;
            sum=0;
        }
    }
    int ans=0;
    for(int i=N-1;i>=0;i--){
        ans=ans*10+arr[i];
    }
    return ans;
}