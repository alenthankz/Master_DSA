// rearrange a sorted array such that even idex is max and odd index is min

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    vector<int>arr;

    int maxIdx=n-1,minIdx=0;
    int maxEle = arr[n-1]+1;

    for(int i =0;i<n;i++){
        if(i%2==0){
            arr[i]+=(arr[maxIdx]%maxEle)*maxEle;
            maxIdx--;
        }else{
            arr[i]+=(arr[minIdx]%maxEle)*maxEle;
            minidx++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]/maxEle;
    }

    return 0;
}