#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i =0;i<n;i++)
typedef vector< vector<int> > Vii;
typedef vector<int> V;

void intialise(V& diff, V&arr){
    diff[0]=arr[0];
    diff[10]=0;
    loop(i,10){
        if(i==0)continue;
        diff[i]=arr[i]-arr[i-1];
    }
}
void update(V& diff, int l, int r, int val){
    diff[l]+=val;
    diff[r+1]-=val;
}

void print(V&finArr,V&diff,int n){
    loop(i,n){
        if(i==0) finArr[i]=diff[i];
        else finArr[i]= diff[i]+finArr[i-1];
    }
}

int main(){
    int n =10;
    int val =10;
    Vii queries(n,vector<int>(2,0));
    V arr (n,0);
    V diff(n+1,0);

    loop(i,n){
        update(diff,queries[i][0],queries[i][1],val);
    }

    V finArr(n,0);
    print(finArr,diff,n);
    
    loop(i,n){
        cout<<finArr[i]<<" ";
    }
    cout<<endl;

    return 0;
}