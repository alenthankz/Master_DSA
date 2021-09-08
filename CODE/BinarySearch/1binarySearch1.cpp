#include<bits/stdc++.h>
using namespace std;

int binarySearch(int * arr,int low,int high,int k){
    while(low<=high){
        int mid = low + high /2;
        if(arr[mid]==k)return k;
        else if(arr[mid]<k)low =mid+1;
        else high =mid-1;
    }
}
// books page allotment question
bool isPossible(int * arr ,int n,int curr_min,int d){
    int curr_sum=0;
    int m =1;
    for(int i =0;i<n;i++){
        if(arr[i]>curr_min)return false;
        if(arr[i]+curr_sum>curr_min){
            m++;
            curr_sum=arr[i];
            if(m>d)return false;
        }
        else curr_sum+=arr[i];
    }
}

int modifiedBS(int * arr,int n,int d){
    int ans=INT_MAX;
    int sum =0;
    for(int i =0;i<n;i++){
        sum+=arr[i];
    }
    int low =0;
    int high =sum;
    while(low<=high){
        int mid =(low + high)/2;

        if(isPossible(arr,n,mid,d)){
            ans =min(ans,mid);
            high =mid-1;
        }
        else low =mid +1;
    }
    cout<<ans;
}
int main(){
    int input[5]={1,2,3,4,5};
    int d=3; //partition array into d such that maxsum of partition is minimized

    modifiedBS(input,5,d);
    
    return 0;
}