// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// next smallest element
vector<int> nextGreaterPermutation(int N, vector<int> arr){
    stack<int>stk;
    int n =N;
    int i;
    for( i =N-1;i>=0;i--){
        if(stk.empty() || arr[stk.top()]>arr[i] )
        {
            int l =stk.top(),r=N-1;
            while(l<r){
                int temp =arr[l];
                arr[l]=arr[r];
                arr[r]=temp;
                l++;r--;
            }
            while(arr[stk.top()]<arr[i])stk.pop();
            int temp =arr[i];
            arr[i]=arr[stk.top()];
            arr[stk.top()]=temp;
            break;
        }
        stk.push(i);
    }
    // cout<<i<<" hi";
    if(i==-1){
        int l =0,r=N-1;
        while(l<r){
            int temp =arr[l];
            arr[l]=arr[r];
            arr[r]=temp;
            l++;r--;
        }
    }
    return arr;
}

// { Driver Code Starts.

int main(){
  
    return 0;
}  // } Driver Code Ends