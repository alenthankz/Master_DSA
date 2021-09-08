#include<bits/stdc++.h>
using namespace std;

bool isBalanced(char * input,int n){
    stack<char>stk;
    for(int i =0;i<n;i++){
        if(input[i]=='{' || input[i]=='[' || input[i]=='('){
            stk.push(input[i]);
            continue;
        }
        if(stk.empty())return false;
        else{
            switch(input[i]){
                case ']':{
                    char s =stk.top();stk.pop();
                    if(s=='{' ||s=='(')return false;
                    break;
                }
                case ')':{
                    char s =stk.top();stk.pop();
                    if(s=='{' ||s=='[')return false;
                    break;
                }
                case '}':{
                    char s =stk.top();stk.pop();
                    if(s=='[' ||s=='(')return false;
                    break;
                }
            }
        }
    }
    return(stk.empty());
}

int main(){
    char input[]={'[','[','{','}','(',')',']',']'};
    int n =sizeof(input)/sizeof(input[0]);
    cout<<isBalanced(input,n)<<endl;
    return 0;
}