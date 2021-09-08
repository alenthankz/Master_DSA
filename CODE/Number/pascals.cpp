// return  nth pascals line

#include<bits/stdc++.h>
using namespace std;

vector<int>pascals(int n){
    if(n==2) return vector<int>(2,1);
    vector<int>pasPrev=pascals(n-1);
    vector<int>pasHere(n,1);
    for(int i=1;i<n-1;i++){
        pasHere[i]=pasPrev[i-1]+pasPrev[i];
    }
    return pasHere;
}


int main(){
    vector<int>ans = pascals(5);
    for(int i =0;i<5;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}