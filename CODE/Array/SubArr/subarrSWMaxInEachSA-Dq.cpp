#include<bits/stdc++.h>
using namespace std;


int main(){
    int input[5]={1,5,2,4,3};
    deque<int>Dq;
    int k=3;
    
    for(int i=0;i<k;i++){
        while(!Dq.empty() && input[Dq.back()]<=input[i])Dq.pop_back();
        Dq.push_back(i);
    }

    for(int i=k;i<5;i++)
    {
        cout<<input[Dq.front()]<<endl;

        while( !Dq.empty() && Dq.front()<=i-k )
        Dq.pop_front();

        while(!Dq.empty() && input[Dq.back()]<=input[i])Dq.pop_back();
        Dq.push_back(i);
        
    }
    cout<<input[Dq.front()];
}