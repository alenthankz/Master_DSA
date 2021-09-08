#include<bits/stdc++.h>
using namespace std;


int toggleBits(int N , int L , int R) {
        if(N==1)return 0;
        int m = (1 << R) - 1;
        int n = (1<<(L-1))-1;
        
        int k = m^n;
        
        return N ^ k ;
    }