//we have a number k and an array arr
//traverse the arr if the arr value is positive then change it to sum of next k values
//else if the arr value is negative change it to sum of last three negative values




#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i =0;i<n;i++) 
typedef vector< vector<int> > VVI;
typedef vector< int > VI;


void fn(int *arr,int n,int k){
    VI prefix(n,arr[0]);
    VI suffix(n,arr[n-1]);
    for(int i =1;i<n;i++) prefix[i]=arr[i]+prefix[i-1];
    for(int i =n-2;i>=0;i--) suffix[i]=arr[i]+suffix[i+1];
    VI output(n,0);
    for(int i =0;i<n;i++){
        if(arr[i]>0){
            if(i+k<n){output[i]=prefix[i+k]-prefix[i];}
            else{output[i]=prefix[n-1]-prefix[i]+prefix[i+k-n];}
        }else{
            if(i-k>=0){output[i] =suffix[i-k]-suffix[i];}
            else{ output[i] =suffix[0]-suffix[i]+ suffix[n+i-k]; }
        }
    }
    for(int i =0;i<n;i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={1,2,3,-4,5,6,-7,8,-9,10};
    int n=10;
    fn(arr,n,3);

    return 0;

}