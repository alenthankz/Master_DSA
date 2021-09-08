// given an array and lot of queries find xor in range l , r in o(1) time
//  idea : a xor a =0 && a xor 0 =a

#include<bits/stdc++.h>
using namespace std;


int main(){
    int n ;
    int arr[10];
    int prefix[10];
    prefix[0]=arr[0];
    for(int i =1;i<n;i++){
        prefix[i]=prefix[i-1]^arr[i];
    }
    int l,r;
    int ans = prefix[r]^prefix[l-1];
}