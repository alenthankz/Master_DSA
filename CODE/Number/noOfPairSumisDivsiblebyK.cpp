// Count pairs in array whose sum is divisible by K
#include<bits/stdc++.h>
using namespace std;

/*
if k was 4;
If both are divisible by 4.
If one of them is equal to 1 modulo 4 and other is 3 modulo 4. For instance, (1, 3), (5, 7), (5, 11).
If both of them is equal to 2 modulo 4 i.e., (2, 2), (2, 6), (6, 10)
*/
int count(int arr[] ,int n,int k){
    vector<int>freq(k,0);
    for(int i =0;i<n;i++){
        ++freq[arr[i]%k];
    }
    int ans=0;
    ans+=freq[0]*(freq[0]-1)/2;
    for(int i =1;i<=k/2 && i!=(k-i);i++){
        ans+=freq[i]*freq[k-i];
    }
    if(k%2==0)
        ans+=freq[k/2]*(freq[k/2]-1)/2;
    
    return ans;
}


int main(){
    return 0;
}