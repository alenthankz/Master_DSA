//1 first occurence of a key
//2 last occurence of a key
//3 index of least element greate than key (upperbound)
//4 index of greatest element less than key (lowerbound)

#include<bits/stdc++.h>
using namespace std;

int firstOccurence(int low ,int high , int key ,int arr[]){
    int ans=-1;
    while(low<=high){
        int mid =(low+high)/2;
        if(arr[mid]<key)low=mid+1;
        else if(arr[mid]>key)high=mid-1;
        else if(arr[mid]==key){ans=mid;high=mid-1;}
    }
}

int lastOccurence(int low ,int high , int key ,int arr[]){
    int ans=-1;
    while(low<=high){
        int mid =(low+high)/2;
        if(arr[mid]<key)low=mid+1;
        else if(arr[mid]>key)high=mid-1;
        else if(arr[mid]==key){ans=mid;low=mid+1;}
    }
}

int upperBound(int low ,int high , int key ,int arr[]){
    int ans=-1;
    while(low<=high){
        int mid =(low+high)/2;
        if(arr[mid]<=key)low=mid+1;
        else if(arr[mid]>key){ans=mid;high=mid-1;}
    }
}

int lowerBound(int low ,int high , int key ,int arr[]){
    int ans=-1;
    while(low<=high){
        int mid =(low+high)/2;
        if(arr[mid]<key){ans=mid;low=mid+1;}
        else if(arr[mid]>=key)high=mid-1;
    }
}

int main(){
    return 0;
}