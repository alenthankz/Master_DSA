// longest subarr with largest sum
#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
        
        int st=0,start=0,end=0,max_till=INT_MIN,max_ele=INT_MIN;
        int sum_here=0;
        for(int i =0;i<n;i++){
            sum_here+=arr[i];
            if(sum_here<0){st=i+1;sum_here=0;}
            if(sum_here>max_till){
                start=st;end=i;max_till=sum_here;
            }
            if(max_ele<arr[i])max_ele=arr[i];
        }
        //if only negative elements
        if(!max_till)return max_ele;
        return max_till;
}


int main(){
    int input[]={-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n =sizeof(input)/sizeof(input[0]);
    int sum_here=0,sum_max=0;
    int st=0,en=0,s=0;
    for(int i =0;i<n;i++){
        sum_here=sum_here+input[i];
        if(sum_here<0){sum_here=0;s=i+1;}
        else if(sum_here>sum_max){
            sum_max=sum_here;
            st=s;
            en =i;
        }
    }
    cout<<"st: "<<st<<" en: "<<en;
    return 0;
}