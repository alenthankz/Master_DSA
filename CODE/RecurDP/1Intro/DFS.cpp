#include<bits/stdc++.h>
using namespace std;

// HERE ORDER MATTERS (1,1,2)!=(2,1,1)
// **
int ORDERED_REPETING_NORMALDFS(int arr[] ,int n , int sum){
    if(sum==0)return 1;
    if(n==0)return 0;
    int res=0;
    for(int i =0;i<n;i++){
        if(arr[i]<=sum){
            int subRes=ORDERED_REPETING_NORMALDFS(arr,n,sum-arr[i]);
            res+=subRes;
        }
    }
    return res;
}

// **
int ORDERED_NON_REPETING_NORMALDFS(int arr[] ,int n , int sum,vector<int>&visited){
    if(sum==0){
        return 1;
    }
    if(n==0)return 0;
    int res=0;

    for(int i =0;i<n;i++){
        if(!visited[i]){       //this is achieved using visited.
            visited[i]=1;
            if(arr[i]<=sum){
                int subRes=ORDERED_NON_REPETING_NORMALDFS(arr,n,sum-arr[i],visited);
                res+=subRes;
            }
            visited[i]=0;
        }
    }
    return res;
}

// **
int UNORDERED_REPEATING_STARTDFS(int arr[] ,int n ,int st, int sum){
    if(sum==0){
        return 1;
    }
    if(n==0)return 0;
    int res=0;
    for(int i =st;i<n;i++){ //i =st;
        if(arr[i]<=sum){
            int subRes=UNORDERED_REPEATING_STARTDFS(arr,n,i,sum-arr[i]);
            res+=subRes;
        }
    }
    return res;
}

// **
int UNORDERED_NON_REPEATING_STARTDFS(int arr[] ,int n ,int st, int sum){
    if(sum==0){
        return 1;
    }
    if(n==0)return 0;
    int res=0;
    for(int i =st+1;i<n;i++){ //i =st+1;
        if(arr[i]<=sum){
            int subRes=UNORDERED_NON_REPEATING_STARTDFS(arr,n,i,sum-arr[i]);
            res+=subRes;
        }
    }
    return res;
}


int main(){
    int arr[]={1,2,3};
    int sum=5;
    return 0;
}