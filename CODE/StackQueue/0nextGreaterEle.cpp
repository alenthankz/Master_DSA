#include<bits/stdc++.h>
using namespace std;

int main(){
    int input[5]={1,3,2,5,4};
    stack<int>s;
    int n =5;
    for(int i =0;i<n;i++){
        while(!s.empty() && input[s.top()]<input[i]){
            int idx =s.top();s.pop();
            cout<<input[idx]<<"->"<<input[i]<<endl;
        }
        s.push(i);
    }
    // important you can make outer loop while and no inner loop
    // some problem highly require it;
    /*
    int i;
    while(i<n){
        if(s.empty() || input[s.top()]>=input[i]) s.push(i++);
        else{
            int idx=s.top();s.pop();
            cout<<input[idx]<<"->"<<input[i]<<endl;
        }
    }
    */
    return 0;
}