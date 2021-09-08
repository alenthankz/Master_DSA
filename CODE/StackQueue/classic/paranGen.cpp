// generate valid paraenthises
#include<bits/stdc++.h>
using namespace std;
void genParn(int o,int c,string str){
    if(o==0 && c ==0){
        cout<<str<<endl;
    }
    if(o>c)return ;
    if(o>=1)genParn(o-1,c,str+"(");
    if(c>=1)genParn(o,c-1,str+")");
}

int main(){
    string str="";
    int n =4;
    genParn(n/2,n/2,str);
    return 0;
}