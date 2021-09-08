#include<bits/stdc++.h>
using namespace std;

vector<int> kthLargest(int k, int arr[], int n) {
    vector<int>ans(n);
    priority_queue<int,vector<int>,greater<int> >pq;
    for(int i =0;i<n;i++){
        if(pq.size()<k)pq.push(arr[i]);
        else{
            if(arr[i]>pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        if(pq.size()<k)ans[i]=-1;
        else ans[i]=pq.top();
    }
    return ans;
}