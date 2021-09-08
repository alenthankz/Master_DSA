#include<bits/stdc++.h>
using namespace std;

int evaluate(string str){
    stack<int>s;
    for(int i=0;i<str.size();i++){
        if(str[i]>='1' && str[i]<='9')s.push(str[i]-'0');
        else{
            int b =s.top();s.pop();
            int a =s.top();s.pop();
            int c;
            switch(str[i]){
                case '+': {c=a+b;break;}
                case '-': {c=a-b;break;}
                case '*': {c=a*b;break;}
                case '/': {c=a/b;break;}
            }
            s.push(c);
        }
    }
    return s.top();
}

int main(){
    string exp="231*+9-";
    cout<<evaluate(exp);
    return 0;
}