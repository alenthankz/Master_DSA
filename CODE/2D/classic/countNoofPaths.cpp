#include<bits/stdc++.h>
using namespace std;
// count number of paths from 0,0 to n-1,m-1

int counNoofPaaths(int n ,int m){
    if(n==1||m==1)return 1;
    return counNoofPaaths(n-1,m) + counNoofPaaths(n,m-1);
}

int main(){
    cout<<counNoofPaaths(5,6);
    return 0;
}