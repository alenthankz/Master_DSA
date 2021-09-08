#include<bits/stdc++.h>
using namespace std;

void solution(vector<int>&arr ,int n){
    vector<int>valu1(n,1);
    vector<int>valu2(n,1);
    for(int i =1;i<n;i++){
        if(arr[i-1]<arr[i]){
            valu1[i]=valu1[i-1]+1;
        }
    }
    for(int i =n-2;i>=0;i--){
        if(arr[i+1]<arr[i]){
            valu2[i]=valu2[i+1]+1;
        }
    }
    for(int i =0;i<n;i++){
        cout<<max(valu1[i],valu2[i])<<" ";
    }

}


int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    solution(arr,n);
    
}