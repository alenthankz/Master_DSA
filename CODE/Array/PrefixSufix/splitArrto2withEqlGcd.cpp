#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a==0)return b;
    return gcd(b%a,a);
}


int main(){
    int input[]={ 8, 4, 4, 8, 12 };
    int n =sizeof(input)/sizeof(input[0]);
    int * prefix =new int[5];
    int * sufix =new int[5];
    prefix[0]=input[0];sufix[n-1]=input[n-1];
    for(int i =1;i<n;i++){
        prefix[i]=gcd(prefix[i-1],input[i]);
        sufix[n-1-i]=gcd(sufix[n-i],input[n-1-i]);
    }
    int count =0;
    for(int i =0;i<n;i++){
        if(sufix[i+1]==prefix[i])count++;
    }
    cout<<count;
    return 0;
}

