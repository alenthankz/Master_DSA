#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/geek-collects-the-balls5515/1#

int maxBalls(int N, int M, int a[], int b[]){
        int i =0,j=0;
        int first=0,second=0,res=0;
        while(i<N && j<M ){
            if(a[i]<b[j])first+=a[i++];
            else if(a[i]>b[j])second+=b[j++];
            else{
                res+=max(first,second)+a[i];
                ++i;++j;
                first=second=0;
            }
        }
        while(i<N){
            first+=a[i++];
        }
        while(j<M){
            second+=b[j++];
        }
        res+=max(first,second);
        
        return res;
    }