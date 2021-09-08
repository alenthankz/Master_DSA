#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){

    for(int i=0;i<n;i++){
        int minIdx=i;
        for(int j=i+1;j<n;i++){
            if(arr[j]<arr[minIdx])minIdx=j;
        }
        swap(&arr[i],&arr[minIdx]);
    }

}