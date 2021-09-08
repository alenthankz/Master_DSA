#include<bits/stdc++.h>
using namespace std;
// even ends at zero ,odd ends at 1
// right most set bit : a&~(a-1)
// power of 2: num && !(num & (num-1) )
// n & 2n contain same no of 1 bit 
// >> right shift ,divide by two or cut the last binary position 5>>1 =10|1
void printBin(int a){
    if(a==0)return;
    printBin(a>>1);
    (a&1)?cout<<"1":cout<<"0";
}

int countsetB(int a){
    int count =0;
    while(a){
        if(a&1)count++;
        a>>=1;
    }
    return count;
}
void swapEvenOddB(int a){
    unsigned  int even = a & 0xAAAAAAAA;
    unsigned  int odd  = a & 0x55555555;
    even<<=1;
    odd>>=1;
    cout<<(even | odd);
}

int leftRotate(int n, unsigned int d) 
{ 
    return (n << d)|(n >> (32 - d)); 
} 


int noOfFlips(int a,int b){
    int c = a^b;
    return countsetB(c);
}

int main(){
    printBin(5);cout<<endl;
    cout<<countsetB(5)<<endl;
    swapEvenOddB(5);cout<<endl;
    return 0;
}