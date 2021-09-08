#include<bits/stdc++.h>
using namespace std;
int knapsackRec(int * val,int * wt,int W,int n){
    if(n==0 || W==0)return 0;
    if(wt[n-1]>W) return knapsackRec(val,wt,W,n-1);
    else return max(knapsackRec(val,wt,W,n-1),val[n-1]+knapsackRec(val,wt,W-wt[n-1],n-1));
}

int knapsackDp(int * val,int * wt,int W,int n){
    vector< vector<int> >K(n+1,vector<int>(W+1,0));
    for(int i =1;i<=n;i++){
        for(int j=1;j<=W;j++){
            
            if(j>=wt[i-1]){
                K[i][j]=max(K[i-1][j],val[i-1]+K[i-1][j-wt[i-1]]);
            }else K[i][j]=K[i-1][j];
            
        }
    }
    return K[n][W];
}

int main(){
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout<<knapsackRec(val,wt,W,n)<<endl;;
    cout<<knapsackDp(val,wt,W,n)<<endl;;
    return 0;
}