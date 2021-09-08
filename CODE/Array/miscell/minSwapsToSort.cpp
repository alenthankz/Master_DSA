#include<bits/stdc++.h>
using namespace std;

int main(){
    int input[]={1,5,4,3,2};
    int n =5;
    int *inputS =new int[5];
    for(int i =0;i<5;i++){
        inputS[i]=input[i];
    }
    sort(inputS,inputS+5);
    int count=0;
    for(int i=0;i<5;i++){
        if(input[i]!=inputS[i])count++;
    }
    cout<<count/2;
    return 0;
}