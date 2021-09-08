//Swap all occurrences of two characters to get lexicographically smallest string
#include<bits/stdc++.h>
using namespace std;

string fn(string str,int n){

    vector<int>ch(26,-1);
    for(int i =0;i<n;i++){
        if(ch[str[i]-'a']==-1)
            ch[str[i]-'a']=i;
    }
    int i,j;
    for(i=0;i<n;i++){
        for(j =0;j<str[i]-'a';j++){
            int flag=0;
            if(ch[j]>ch[str[i]-'a']){flag=1;break;}
            if(flag)break;
        }  
    }
    if(i<n){
        char ch1=str[i];
        char ch2=str['a'+j];
        for(int i =0;i<n;i++)
        {
            if(str[i]==ch1)str[i]=ch2;
            else if (str[i]==ch2)str[i]=ch1;
        }
    }
    return str;
}

int main(){
    string str=" ";
}