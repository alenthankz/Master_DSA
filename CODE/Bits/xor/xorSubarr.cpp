// xor of all subarr

#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    int arr[10];
    int ans =0;
    for(int i =1;i<=n;i++){
        int val = (i)*(n-i-1);
        if(val%2==1){
            ans^=arr[i-1];
        }
    }
    return 0;
}