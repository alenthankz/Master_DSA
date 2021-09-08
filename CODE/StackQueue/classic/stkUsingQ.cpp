// stack -swap method

#include<bits/stdc++.h>
using namespace std;
class Stack{
    int curr_size;
    queue<int>q1,q2;
    public:
    Stack(){curr_size=0;}
    void push(int x){q1.push(x);curr_size++;}
    int pop(){
        if(q1.empty())return -1;
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        curr_size--;
        int val = q1.front();
        q1.pop();// in top() we insert this value back to q2 & curr_size doesnot decrease
        queue<int>q =q1;
        q1=q2;
        q2=q;
        return val;
    }
    // int top(){
    //     if(q1.empty())return -1;
    //     while(q1.size()!=1){
    //         q2.push(q1.front());
    //         q1.pop();
    //     }
    //     int val = q1.front();
    //     q1.pop();
    //     q2.push(val);
    //     queue<int>q =q1;
    //     q1=q2;
    //     q2=q;
    //     return val;
    // }
    bool empty(){
        if(curr_size==0)return true;
        else false;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.pop();
    // cout<<s.top();
}