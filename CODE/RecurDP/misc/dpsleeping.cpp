#include<bits/stdc++.h>
using namespace std;
#define loop(i,N) for(int i =0;i<N;i++)
typedef vector<int> Vi;

int find_good(int N,Vi&arr,int h,int l, int r,int nt,int i,vector< vector<int> >&dp){
   
    if(i==N){
        return (nt>=l && nt<=r)==1?1:0;
    };
    if(!dp[i][nt]==-1)return dp[i][nt];
    int ans=0;
    if(nt<=r && nt>=l)ans=1;
    dp[i][nt] =ans+ max( find_good(N,arr,h,l,r,(arr[i]+nt)%h,  i+1,dp) ,
                            find_good(N,arr,h,l,r,(arr[i]-1+nt)%h,i+1,dp) 
                        );
    
    return dp[i][nt];
}
int main(){
    int N,h,l,r;
    cin>>N;
    cin>>h;
    cin>>l;
    cin>>r;
    Vi arr(N);
    loop(i,N){
        cin>>arr[i];
    }
    vector< vector<int> > dp(N,vector<int>(h,-1));
    cout<<find_good(N,arr,h,l,r,0,0 ,dp);
}