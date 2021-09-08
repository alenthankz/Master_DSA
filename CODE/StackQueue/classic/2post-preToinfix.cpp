#include<bits/stdc++.h>
using namespace std;


bool isOperand(char x)
{
   return (x >= 'a' && x <= 'z') ||
          (x >= 'A' && x <= 'Z');
}

string postToinfix(string exp)
{
    stack<string> s;
    for (int i=0; exp[i]!='\0'; i++)
    {
        if (isOperand(exp[i]))
        {
           string op(1, exp[i]);
           s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] +
                   op1 + ")");
        }
    }
    return s.top();
}

string preToinfix(string s){
    // do the same but from right to left , thatis  n-1 to 0;
}


int main(){
    string pre=""; 
    string post=""; 
    return 0;
}