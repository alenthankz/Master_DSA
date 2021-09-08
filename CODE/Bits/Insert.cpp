// given a bitnumber A and bitnumber B insert A in B at given pos
//  eg B 1010 A 100 pos 2 => 1010010
#include<bits/stdc++.h>
using namespace std;

void insertBit(int B ,int A , int pos){

    int mask = 1<<pos-1;
    int len = log2(A)+1;
    mask = mask&B;

    B>>=pos;

    B<<=len;
    B|=A;

    B<<=pos;
    B|=mask;

    cout<<B;
}

int main(){
    int B =10,A=4,pos=2;
    insertBit(B,A,pos);
    return 0;
}