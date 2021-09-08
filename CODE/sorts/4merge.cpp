#include<bits/stdc++.h>
using namespace std;

void mergge(int arr[],int start,int mid,int end){
}
    int n2 = end-mid;
    int n1 = mid-start+1;
    int arr1[n1];
    int arr2[n2];

    for(int i =start;i<=mid;i++)arr1[i-start]=arr[i]; 
    for(int i =mid+1;i<=end;i++)arr2[i-(mid+1)]=arr[i]; 

    int k=0,i=0,j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr[start+k]=arr1[i];
            i++;
        }else{
             arr[start+k]=arr2[j];
             j++;
        }
        k++;
    }
    
}

void mergeSort(int arr[],int start,end){
    if(start>=end)return;
    int mid =(start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    mergge(arr,start,mid,end);
}