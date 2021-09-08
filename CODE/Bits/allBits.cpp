// check if all bits are set 
// check if all bts are alternating

#include<bits/stdc++.h>
using namespace std;

bool ifAllBitsSet(int x){
    if(x&(x+1)==0)return true;
    return false;
}

bool ifAllBitsAlternating(int x){
    int y = x^(x-1);// example : 1010 ^ 1001 =0011 all bits will be set 
    if(ifAllBitsSet(y))return true;
    else return false;
}

int main(){
    return 0;
}