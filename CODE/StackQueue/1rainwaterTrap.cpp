#include<bits/stdc++.h>
using namespace std;

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
    int arr[]={ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int n=12;
    long long int ans =0;
    stack<int>s;
    for(int i =0;i<n;i++){
        while(!s.empty() && arr[s.top()]<arr[i]){
            
        }
        s.push(i);
    }

    return 0;
}