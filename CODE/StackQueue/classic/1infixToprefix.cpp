#include<bits/stdc++.h>
using namespace std;
int precedence(char a){
    switch(a){
        case '^':{return 3;break;}
        case '*':{return 2;break;}
        case '/':{return 2;break;}
        case '+':{return 1;break;}
        case '-':{return 1;break;}
        default:return -1;
    }
}
bool isOperator(char a){
    if(a =='*' ||a=='^' || a=='/' || a=='+' || a=='-')return true;
    else return false;
}
string inTOpre(string str){
    stack<char>s;
    s.push('$');
    string res="";
    for(int i =0;i<str.size();i++){
        if(str[i]=='(')s.push('(');
        else if(str[i]==')'){
            while(s.top()!='(' && s.top()!='$'){
                res+=s.top();s.pop();
            }
            if(s.top()=='('){
                s.pop();
            }
        }
        else if(!isOperator(str[i]))res+=str[i];
        else if(isOperator(str[i])){
            // next smallest
            while(precedence(s.top())>=precedence(str[i])  && s.top()!='$'){
                res+=s.top();s.pop();
            }
            s.push(str[i]);
        }
    }
    while(s.top()!='$'){
        res+=s.top();s.pop();
    }
    return res;
} 

int main(){
    string exp = "a+b*(c^d-e)^(f+g*h)-i"; 
    cout<<inTOpre(exp);
    return 0;
}