#include<bits/stdc++.h>
using namespace std;

void subseqRecur(int * input,int n,int ind,vector<int>subNow){
   
    if(n==ind){
        for(int i=0;i<subNow.size();i++){
            cout<<subNow[i]<<" ";
        }
        cout<<endl;
    }
    else{
        subseqRecur(input ,n,ind+1, subNow);
        subNow.push_back(input[ind]);
        subseqRecur(input,n,ind+1,subNow);
    }
    return;
}//unlike array vector when passed create new memory

void subseqLisIdea(int * input,int n,vector<int>&subnow){
    if(n==1){
        subnow.push_back(input[n-1]);
        return;
    }
    for(int i=1;i<n;i++){
         
        subseqLisIdea(input,i,subnow);
        subnow.push_back(input[n-1]);
        for(int i=0;i<subnow.size();i++){
            cout<<subnow[i]<<" ";
        }
        cout<<endl;
    }
}


void subseqIter(int *  input ,int n ){
    long long m = pow(2,n);
    for(long long i =0;i<m;i++){
        for(int j =0;j<n;j++){
            if(1<<j & i){
                cout<<input[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int input[5]={1,2,3,4,5};
    int  n =5;
    vector<int>B;
    // subseqRecur(input,n,0,B);
    subseqIter(input,n);
    return 0;
}