#include<bits/stdc++.h>
// this idea can also be used to solve rainwater trap stack
//  max of j-1 such that arr[j]>arr[i]
/*
The idea is to traverse every array element and find the highest bars on left and right sides(not including) 
Take the smaller of two heights. The difference between the smaller height 
and height of the current element is the amount of water that can be stored in this array element.
*/
using namespace std;

int trappingWater(int arr[], int n){
        int* maxL = new int[n];
        int* maxR = new int[n];
        maxL[0]=arr[0];
        maxR[n-1]=arr[n-1];
        for(int i =1;i<n;i++){
            maxL[i]=max(maxL[i-1],arr[i-1]);
            maxR[n-i-1]=max(maxR[n-i],arr[n-i]);
        }
       
        int ans =0;
        for(int i =1;i<n-1;i++){
            int v=min(maxL[i],maxR[i])-arr[i];
            if(v>0)ans+=v;
        }
        return ans;
}

// actaully nextgreater element == next greater element in left
// in next greater element we PoP if we meet GreateR element.
// the ele just before top of stack is obviously GreateR then ToP

int trappingWaterSt(int arr[], int n){
        stack<int>s;
        int ans=0;
        for(int i =0;i<n;i++){
            while(!s.empty() && (arr[s.top()]<arr[i]) ){
                int currheight = arr[s.top()];s.pop();
                if(s.empty())break;
                
                int distance = i - s.top()-1;
                int he = min(arr[i],arr[s.top()])-currheight ;
                
                ans+=(he*distance);
            }
            s.push(i);
        }
        return ans;
}

int main(){
    int arr[] = { 9, 2, 3, 4, 5,
                  6, 7, 8, 18, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<trappingWater(arr, n);
    return 0;
}