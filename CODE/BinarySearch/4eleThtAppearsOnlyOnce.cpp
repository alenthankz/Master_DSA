/*
Given a sorted array in which all elements appear
 twice (one after one) and one element appears only once
*/

#include<bits/stdc++.h>
using namespace std;

int modifiedBS(int arr[] ,int low ,int high){
    
    while(low<=high){
        if(low==high)return arr[low]; //important edge case condition remember
        int mid = (low+high)/2;

        if(mid%2==0){
            if(arr[mid]==arr[mid+1])low=mid+2;
            else high=mid;
        }
        else{
            if(arr[mid]==arr[mid-1])low=mid+1;
            else high =mid-1; //that one element is sure in even position.
        }
    }
    

}

int main(){
    return 0;
}