#include<bits/stdc++.h>
using namespace std;

class Mystack{
    public:
    int minEle ;
    stack<int>stk;
    void mypush(int val){
        if(!stk.empty()){
            stk.push(val);
            minEle = val;
        }
        else if( minEle>val){
            stk.push(2*val-minEle);
            minEle=val;
        }else{
            stk.push(val);
        }
    }
    void mypop(){
        int curr = stk.top();
        if(curr<minEle){
            cout<<minEle;
            minEle=2*minEle-curr;
        }else{
            cout<<curr;
        }
    }
};

int main(){

    return 0;
}