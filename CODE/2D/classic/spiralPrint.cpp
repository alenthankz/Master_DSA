// C++ Program to print a matrix spirally
 
#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 6

int main(){
    int mat[R][C] = { { 1,  2,   3,   4,   5,    6 },
                    {   7,  8,   9,   10,  11,   12 },
                    {   13, 14, 15,   16,  17,   18 } };
    
    int t=0,b=R-1,l=0,r=C-1;
    while(t<=b && l<=r){
        for(int i =l;i<=r;i++){
            cout<<mat[t][i]<<" ";
        }
        t++;
        for(int i =t;i<=b;i++){
            cout<<mat[i][r]<<" ";
        }
        r--;
        if(t<=b){
            for(int i=r;i>=l;i--){
                cout<<mat[b][i]<<" ";
            }
            b--;
        }
        if(l<=r){
            for(int i=b;i>=t;i--){
                cout<<mat[i][l]<<" ";
             }
             l++;
        }
        
    }
        
    return 0;
}