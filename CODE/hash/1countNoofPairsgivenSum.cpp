#include<bits/stdc++.h>
using namespace std;

int countPairs(int arr[],int n ,int sum){
    int twice_count=0;
    map<int,int>mp;

    for(int i =0;i<n;i++)mp[arr[i]]++;

    for(int i=0;i<n;i++){
        twice_count+=mp[sum-arr[i]];

        if((sum-arr[i])==arr[i])twice_count--;
    }
    return twice_count/2;

}

int countSubarr(int arr[],int n ,int sum){
   
    int res=0;
    map<int,int>mp;

    int currSum=0;
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        if(currSum==sum)res++;
        if(mp[sum-currSum)res+=mp[sum-currSum];
        mp[currSum]++;
    }
    return res;

}

int countSubarrWithGivenXor(int arr[],int n ,int Xor){
   
    int res=0;
    map<int,int>mp;

    int currXor=0;
    for(int i=0;i<n;i++){
        currXor^=arr[i];
        if(currXor==Xor)res++;
        if(mp[Xor^currXor])res+=mp[Xor^currXor];
        mp[currXor]++;
    }
    return res;

}

