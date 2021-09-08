#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(int N)
    {
    //       11101111   (x)
    //     & 11011110   (x << 1)
    //     ----------
    //       11001110   (x & (x << 1)) 
    //         ^    ^
    //         |    |
    //   trailing 1 removed
        int count=0;
        while(N){
            N=(N&(N<<1));count++;
        }
        return count;
    }

    // a sparsenumber is which dont have concecutive 1s at all
    // so right shift and AND => (N&N>>1)==0 =>sparse