#include<bits/stdc++.h>
using namespace std;


int UNORDERED_REPEATING_NORMALRECUR(int arr[],int n ,int sum){
    if(sum==0)return 1;
    if(sum<0)return 0;
    if(n==0)return 0;
    return UNORDERED_REPEATING_NORMALRECUR(arr,n-1,sum)+UNORDERED_REPEATING_NORMALRECUR(arr,n,sum-arr[n-1]);//here n is not decreased leading to repeatition
}
int UNORDERED_NON_REPEATING_NORMALRECUR(int arr[],int n ,int sum){
    if(sum==0)return 1;
    if(sum<0)return 0;
    if(n==0)return 0;
    return UNORDERED_REPEATING_NORMALRECUR(arr,n-1,sum)+UNORDERED_REPEATING_NORMALRECUR(arr,n-1,sum-arr[n-1]);//here n is decreased hence nonrepeatition
}



int main(){
    int arr[]={1,2,3};
    int sum=5;
    return 0;
}