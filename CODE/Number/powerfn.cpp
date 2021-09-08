#include<bits/stdc++.h>
using namespace std;

vector<int>dp(10000,-1);
int powerFn(int x , int n){
    if(n==0)return 1;
    int val = powerFn(x,n/2);
    if(n%2==0)
     return val*val;
    else
     return x * val*val;
}

int main(){
    int x =5,n=7;
    return 0;
}

// TC : log(n);