// Length of the longest substring without repeating characters


#include<bits/stdc++.h>
using namespace std;
// seecond method other than sw is imp here

int longestUniqueSubSW(string str){
    set<char>s;
    int st =0,e=0;
    int len=0;
    for(int i =0;i<str.size();i++){
        if(s.find(str[i])!=s.end()){
            int j =st;
            while(str[j]!=str[i])j++;
            st=j+1;
        }
        {
            s.insert(str[i]);
            e=i;
            len =max(len,e-st+1);
        }
    }
    return len;
}


// saving the last found index is quite powerful for sw

int secondMethod(string str){
    int res =0;
    vector<char>last_index(256,-1);
    int i =0;
    for(int j =0;j<str.size();j++){
        i =max(last_index[str[j]]+1,i);
        res =max(res,j-i+1);
        last_index[str[j]]=j;
    }
    return res;
    //alternate implmentation of same concept
    /*
    map<char,int>mp;
    int st=0,en=0,len=0,stt=0;
    for(int i =0;i<str.size();i++){
        if(mp[str[i]]){
            st =mp[str[i]];
        }
        en=i;
        mp[str[i]]=i+1;                         // be careful while saving index 0 to map,
        len=max(len,en-st+1);                   // map may think it is the 0 by default in map
        if(len==(en-st+1))stt=st;
    }
    cout<<str.substr(stt,len);
    return len;
    */
}


int main(){
    string str = "alentarun"; 
    cout<<longestUniqueSubSW(str)<<endl;
    cout<<secondMethod(str);
    return 0;
    return 0;
}