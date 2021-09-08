// eg: 23can be ae af ag be bf bg ce cf cg.
#include<bits/stdc++.h>
using namespace std;

void dfs(string number,int n,string * V,vector<string>&result,int index,string str){
    if(index==n){
        result.push_back(str);
        return;
    }
    // cout<<index<<" ";
    int m =3;
    int no = number[index]-'0';
    // cout<<no<<" ";
    if(no ==7 || no==9) m=4;
    for(int i =0;i<m;i++){
        // cout<<i<<" ";
        dfs(number,n,V,result,index+1,str+V[no][i]);
    }
    
}

int main(){
    string number ="9447535254";
    int n =number.size();
    string V[]={"...","...","abc","def" ,"hij" ,"klm","npo","pqrs","tuv","wxyz"};
    vector<string>result;
    dfs(number,n,V,result,0,"");
    for(int i =0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}