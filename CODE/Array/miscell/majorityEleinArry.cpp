#include<bits/stdc++.h>
using namespace std;
//this is a greedy alogithm we have to find an element if exist that has a count more than n/2
// here if n is even there should be two concecutive ele
// if n is odd , either there should be two concecutive ele , or last ele is the majority element
int findCandidate(int arr[],int n ){
    int idx=0,count=1;
    for(int i =1;i<n;i++){
        if(arr[idx]==arr[i])count++;
        else count--;
        if(count==0){
            count=1;
            idx=i;
        }
    }
    return idx;
} 

bool verifyCandidate(int arr[],int n ,int idx){
    int count=0;
    for(int i =0;i<n;i++){
        if(arr[i]==arr[idx])count++;
    }
    if(count>(n/2))return 1;
    else return 0;
}

int findMajority(int arr[],int n){
    int idx = findCandidate(arr,n);
    if(verifyCandidate(arr,n,idx))return arr[idx];
    else return -1;
}

int main(){
    return 0;
}