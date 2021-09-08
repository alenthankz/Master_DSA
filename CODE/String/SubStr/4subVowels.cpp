// smallest substrings that contain all vowels

#include<bits/stdc++.h>
using namespace std;
bool isVowel(char x){
    if(x=='a' || x=='e' || x=='i'|| x=='o' ||x=='u')
    return true;
    else return false;
}

int idx(char x){
    if(x=='a')return 0;
    if(x=='e')return 1;
    if(x=='i')return 2;
    if(x=='o')return 3;
    if(x=='u')return 4;
}

int main(){
    string str ="abaciteoeainuoehaiu";
    int last_entry[5]={0};
    int freq[5]={0};
    int count=0;
    int st =0;
    int start;
    int len=INT_MAX;
    
    for(int i =0;i<str.size();i++){
        if(isVowel(str[i])){
            if(freq[  idx(str[i]) ]==0){freq[idx(str[i])]++;count++;}
            last_entry[ idx(str[i]) ]=i;
        }
        if(count ==5){
            int st =*min_element(last_entry,last_entry+5);
            len =min(len,i-st+1);
            if(len ==(i-st+1))start=st;
        }
        
    }
    cout<<str.substr(start,len);
    return 0;
}