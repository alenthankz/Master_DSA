// first missing smallest interger from 0 to ..

#include<bits/stdc++.h>
using namespace std;

int firstMissing(int arr[],int n){

    int low=0,high=n-1;
    while(low<=high){
        if(low!=arr[low])return low;
        int mid=(low+high)/2;
        if(arr[mid]==mid)low=mid+1;
        else high=mid;
    }
    return high+1;

}
// O(logn)

int MissingNumber(vector<int>& array, int n) {
        int x1 = 0;
        int x2 = 0;
     
        for (int i = 0; i < n-1; i++)
            x1 = x1 ^ array[i];
     
        for (int i = 1; i <=n ; i++)
            x2 = x2 ^ i;
     
        return (x1 ^ x2);
}
//O(n)


// IF FIRST MISSING AND REPEATING USE HASH MAP or use Xor and use rightmost set bit
int main(){
    int n =5;
    int input[5]={0,1,4,5,6};
    cout<<findFirstMissing(input,0,4);
    return 0;
}