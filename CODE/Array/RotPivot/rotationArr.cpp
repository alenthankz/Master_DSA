#include<bits/stdc++.h>
using namespace std;

void reverse(int * input,int start,int end){
    while(start<end){
        int temp=input[start];input[start]=input[end];input[end]=temp;
        start++;end--;
    }
}

void reversal(int * input,int n ,int d){

    if (d == 0) return; 
    d = d % n; 

    reverse(input,0,d-1);
    reverse(input,d,n-1);
    reverse(input,0,n-1);

}

void juggling(int *arr ,int n , int d ){
    int gcd =__gcd(n,d);
    for(int i =0;i<gcd;i++){
        int j =i;
        int temp = arr[i];

        while(1){
            int k =j+d;
            if(k>n)k=k-n;
            if(k==i)break;
            arr[j]=arr[k];
            j=k;
        }
        arr[j]=temp;
    }
    // O(n)
}



int main(){
    int input[5]={1,2,3,4,5};
    int d =2;
    for(int i=0;i<5;i++){
        cout<<input[i]<<" ";
    }
    return 0;
}