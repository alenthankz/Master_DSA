#include<bits/stdc++.h>
using namespace std;
// Given an array A[] of N positive integers. The task is to
//  find the maximum of j - i subjected to the constraint of A[i] <= A[j].
int maxIndexDiff(int arr[], int n) 
{ 
    vector<int>rmax(n,arr[n-1]);
    vector<int>lmin(n,arr[0]);
    
    for(int i =1;i<n;i++){
        lmin[i]=min(lmin[i-1],arr[i]);
        rmax[n-i-1]=max(rmax[n-i],arr[n-i-1]);
    }
    
    int i =0,j=0,ans=-1;
    while(i<n && j<n){
        if(lmin[i]<=rmax[j]){
            ans=max( ans,j-i);
            j++;
        }else{
            i++;
        }
    }
    
    return ans;
}