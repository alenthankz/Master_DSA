#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


//obe more problem about subarr like kadanes
int findSubarray(vector<ll> arr, int n ) {
    map<ll ,int >mp;
    int max_len=0;
    ll sum=0;
    
    for(int i =0;i<n;i++){
        sum+=arr[i];
        if(max_len==0 && arr[i]==0)max_len+=1;
        if(sum==0)max_len=i+1;
        if(mp[sum]) max_len=max( max_len , i-mp[sum]);
        else {
            mp[sum]=i;
        }
    }
    return max_len;
    
}