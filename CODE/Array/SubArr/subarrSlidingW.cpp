#include<bits/stdc++.h>
using namespace std;


int main(){
    int input[6]={1, 4, 45, 6, 10, 19};
    int sum = 51,sumNow=0;
    int start=0,min=INT_MAX,len=0;
    for(int end =0;end<6;end++){
        sumNow+=input[end];
        while(sumNow>sum && start<=end){
            sumNow-=input[start];
            len =end-start+1;
            start++;
            if(len<min)min=len;
        }
    }
    // subarr can be very simple for example,find the longest continuous elemented subarr.
    cout<<min;
}