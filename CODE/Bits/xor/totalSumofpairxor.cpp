// xor pair (unordered) then take sum
// SAME QUESTION ALSO :Sum of bit differences among all pairs
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=3 ;
    int arr[3]={1,2,3};
    int res=0;
    for(int i =0;i<31;i++){
        int count1=0;
        for(int j =0;j<n;j++){
            if((1<<i)&& arr[j])count1++;
        }
        int p = count1*(n-count1);
        res=res+(1<<i)*ans;
    }
    return 0;
}