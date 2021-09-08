#include<bits/stdc++.h>
using namespace std;

//ordered repeating
int lisRecur(int *input,int n,int & max){
    if(n==1)return 1;
    int res=1;
    for(int i=1;i<n;i++){
        int subRes =1+lisRecur(input,i,max);
        if( input[n-1]>input[i-1] && subRes>res){
            res=subRes;
        }
    }
    if(max<res)
        max=res;

    return res;
}


int lisDp(int arr[],int n){
    int dp[n];
    int parent[n];
    parent[0]=0;
    dp[0]=1;

    for(int i =1;i<n;i++){
        dp[i]=1;parent[i]=i;
        for(int j =0;j<i;j++){
            int subRes=1+dp[j];
            if(arr[i]>arr[j] && subRes>dp[i]){dp[i]=subRes;parent[i]=j;}
        }
    }

    int maxx=INT_MIN,idx=-1;
    for(int i =0;i<n;i++)if(dp[i]>maxx){maxx=dp[i];idx=i;}

    stack<int>stk;

    stk.push(idx);   //here we are pushing idx , you can push arr[idx] if want

    while(parent[idx]!=idx){
        idx=parent[idx];
        stk.push(idx);
    }

}

/* BITIONIC LIS
#include<bits/stdc++.h>
using namespace std;
int lis(int *arr,int n){
    vector<int>liArr(n,1);
    vector<int>ldArr(n,1);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && liArr[j]+1>liArr[i]){
                liArr[i]=liArr[j]+1;
            }
            if(arr[j]>arr[i] && ldArr[j]+1>ldArr[i]){
                ldArr[i]=ldArr[j]+1;
            }
            ans=max(ans,ldArr[i]+liArr[i]-1);
        }
    }
    return ans;
}
int main(){
    int arr[]={1,8,3,7,5,6};int n =6;
    cout<<lis(arr,n);
    return 0;
}*/

int main(){
    int input[5]={1,4,2,3,5};
    cout<<lisDp(input,5);

}