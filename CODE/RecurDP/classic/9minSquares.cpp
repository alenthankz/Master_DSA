#include<bits/stdc++.h>
using namespace std;

// minimum no of squares that add upto a number
// ex: 100 => 1 (10*10)  , 125 => 2 (10*10+5*5) , 98=> 2 (7*7+7*7)

int minSquares(int N){
    if(N==0)return 0;
    int res=INT_MAX;
    for(int i =1;i*i<=N;i++){
        if(i*i<=N){
            int subRes = 1+ minSquares(N-i*i);
            if(subRes<res)res=subRes;
        }
    }
    return res;
}

int main(){
    
    return 0;
}