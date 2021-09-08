// Count number of binary strings without consecutive 1’s 0f length N

//if a represent req strings ending in 0 , then we can append 1/0 at the end to get more req strings
//b rerpresenting req string ening in 1 , then we can append only 0 at the end to get more req strings

//base case for a is 0 and b is 1

// here in this problem we wont deal with the strings explicity but just the count 
// so arrays a and b represent count of them

#include<bits/stdc++.h>
using namespace std;

int countstrings(int n){
    int a[n],b[n];
    a[0]=b[0]=1;
    int i;
    for( i =1;i<n;i++){
        a[i]=a[i-1]+b[i-1];
        b[i]=a[i-1];
    } 
    return a[i-1]+b[i-1];   
}

int main(){
    return 0;
}