#include<bits/stdc++.h>
using namespace std;

struct Custom{
    int var1;
    int var2;
};

int mySortComp(const Custom & a,const Custom & b){
    if(a.var2==b.var2)return a.var1>b.var1;

    return a.var2>b.var2;
}


class myPQComp{
    public:
    int operator()(const Custom & a,const Custom & b){    //original priority_queue will be opposite to what we give
        if(a.var1==b.var1)return a.var2>b.var2;

        return a.var1>b.var1; //inorer of greater of var1
    }
};

int main(){
    int input[5]={3,1,2,4,5};
    Custom cInput[5]={ {1,10},{2,9},{3,8},{4,7},{5,6}};


    // _______SORT__________________
    sort(input,input+5,greater<int>());//need to invoke greater<int>
    for(int i =0;i<5;i++)cout<<input[i]<<" ";
    cout<<endl;
    sort(cInput,cInput+5,mySortComp);
    for(int i =0;i<5;i++)cout<<cInput[i].var1<<" "<<cInput[i].var2<<" ";
    cout<<endl;


    // _______PQ____________________ //priority_queue already sort in greater order unlike sort
    priority_queue<int>pq;
    priority_queue<int,vector<int> ,greater<int> >minpq;//using greater +vector mke it minpq & aslo no need to invoke greater<int> unlike sort
    
    priority_queue<Custom,vector<Custom>,myPQComp >cpq; //opposite of myPQComp will happen here
    for(int i =0;i<5;i++)cpq.push(cInput[i]);   
    for(int i =0;i<5;i++){cout<<cpq.top().var1<<" "<<cpq.top().var2<<" "<<endl;cpq.pop(); }  


    return 0;
}