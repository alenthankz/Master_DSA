#include<bits/stdc++.h>
using namespace std;

void NGECircular(int arr[],int n){
    stack<int>stk;
    vector<int>ans(n,-1);
    for(int i =0;i<2*n;i++){
        while(!stk.empty() && arr[i%n]>arr[stk.top()]){
            ans[stk.top()]=arr[i%n];
            stk.pop();
        }
        stk.push(i%n);
    }
    for(int i =0;i<n;i++){
        cout<<ans[i]<<" ";
    }

}

int main(){
    int arr[]={8,6,3,10,9,2,3};
    int n =sizeof(arr)/sizeof(arr[0]);
    NGECircular(arr,n);
    return 0;
}