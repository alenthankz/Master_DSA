#include<bits/stdc++.h>
using namespace std;

int findPivot(int * arr,int low,int high){
    if(high<low)return -1;
    if(high ==low)return low;
    int mid = low+high/2;
    if(mid<high && arr[mid]>arr[mid+1])
    return mid;
    if(mid>low && arr[mid]<arr[mid-1])
    return mid-1;
    if(arr[low]>arr[mid])
    findPivot(arr,low,mid-1);
    else
    findPivot(arr,mid+1,high);
    
}

int main(){
    int input[5]={3,4,5,1,2};
    cout<<input[findPivot(input,0,4)];
    return 0;
}