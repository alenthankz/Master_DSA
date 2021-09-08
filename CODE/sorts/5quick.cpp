#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot =arr[high];
    int i=low;
    int j =low-1;
    for(int i=low;i<=high;i++){
        if(arr[i]<pivot){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j+1],arr[high]);
    return j+1;
}

void quickSort(int arr[],int low ,int high){

    if(low>=high)return;
    int p = quickSort(arr,low,high);
    quickSort(arr,low,p-1);
    quickSort(arr,p+1,high);
    
}