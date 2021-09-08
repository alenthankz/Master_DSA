// remove the minimum number of paranthesis to get a valid paranthesis ( one state to other + min delete === bfs)

#include<bits/stdc++.h>
using namespace std;

bool isValid(string seq){
    stack<char>stk;
    for(int i =0;i<seq.size();i++){
        if(seq[i]=='(')stk.push('(');
        else{
             if(stk.empty())return false;
             stk.pop();
        }
    }
    return stk.empty();
}
int minDelete(string seq){
    queue< pair<string ,int > > Q;
    Q.push(make_pair(seq,0));
    while(!Q.empty()){
        string curr = Q.front().first;
        int level = Q.front().second;
        Q.pop();
        if( isValid(curr) )return level ;
        for(int i =0;i<seq.size();i++){
            string seqq=curr;
            // cout<<seqq.erase(i,1)<<endl;
            Q.push(make_pair(seqq.erase(i,1),level+1));
        }
    }
}
int main(){
    string seq ="()())()";
    // cout<<isValid("()()()");
    cout<<minDelete(seq);
    return 0;
}