#include<bits/stdc++.h>
using namespace std;
#define N 4

int main(){
    
    string s1,s2,res="";
    int n =s1.size();
    int a =0;
// first make s1 and s2 equal length by adding zero;
    for(int i =n-1;i>=0;i--){
        a += (s1[i]-'0') + (s2[i]-'0');
        res = char(a%2)+res;
        a=a/2;//keep a as carry
    }
    
    return 0;
}