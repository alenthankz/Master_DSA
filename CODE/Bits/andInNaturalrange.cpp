// given a range (a,b) of natural numbers fin the xor
// idea used : check carefully each position: 0 th idex cahnges after one iteration , 1st index after 2 ,2nd index after 4 and so on...
/*
0000
0001
0010
0011
0100
0101
0110
0111
1000
1001
1010
1011
1100
1101
1110
1111
*/

#include<bits/stdc++.h>
using namespace std;


int main(){
    int l,r;
    int diff =r-l+1;
    int ans=0;
    for(int i =0;i<31;i++){
        if((1<<i)<diff){
            ans+=0*(1<<i);
        }else{
            if((l&1<<i) && (r&1<<i))
              ans+=1*(1<<i);
        }
    }
    return 0;
}















      