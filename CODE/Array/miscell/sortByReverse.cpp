
#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i =0;i<n;i++) 
typedef vector< vector<int> > VVI;
typedef vector< int > VI;
typedef pair<int,int> PII;
#define start first
#define finish second

void rev(int * arr, int i ,int j){
    while(i<j){
        int tem = arr[i];
        arr[i]=arr[j];
        arr[j]=tem;
        i++;j--;
    }
}

void sortFn(int * arr, int n){
    int k =1;
    while(k){
        int flag=0;
        for(int i =1;i<n;i++){   
            if(arr[i]<arr[i-1]){
                int st =i-1;i++;
                while(arr[i-1]>arr[i] && (i<n))i++;
                int en =i-1;
                rev(arr,st,en);
                flag=1;
            }
        }
        if(flag==0)return;
    }
}

int main(){
    int arr[]={1,2,4,3,7,6,5,8,9};
    int n=9;
    sortFn(arr,n);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}


