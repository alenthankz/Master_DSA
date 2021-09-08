// find missing and repeating ele in array and in range 1 to n;
#include<bits/stdc++.h>
using namespace std;

void find(int * arr, int n ){
    int x =0, y=0;
    int set_bit =0;
    int Xor = arr[0]; for(int i =1;i<n;i++)Xor=Xor^arr[i];
    set_bit = Xor&-(Xor-1);
    for(int i =0;i<n;i++){
        if(arr[i]&set_bit)x^=arr[i];
        else y^=arr[i];
    }
    for(int i =1;i<=n;i++){
        if(i&set_bit)x^=i;
        else y^=i;
    }
    cout<<x<<" "<<y;
    return;
}

int main(){
    int arr[] = { 1, 3, 4, 5, 5, 6, 2 };
    int n =7;
    find(arr,n);
    return 0;
}