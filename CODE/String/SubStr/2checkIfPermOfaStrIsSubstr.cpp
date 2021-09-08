// check if permutation of a string is substring of another string 


//map equality is also very important 
//dont always get teriified by permutation 


#include<bits/stdc++.h>
using namespace std;

int main(){
    string str1="df",str2="abcdefghi";
    map<char,int>m1;
    map<char,int>m2;
    int k =str1.size();
    if(k>str2.size()){
        cout<<"false";
        return 0;
    }
    int i =0;
    for(i =0;i<k;i++){
        m2[str2[i]]++;
        m1[str1[i]]++;
    }
    if(m1==m2){
        cout<<"True";
        return 0;
    }

    for(i =k;i<str2.size();i++){
        m2[str2[i-k]]--;//repeated letters in the k size //here window size is fixed in some prob it may be variable
        if(m2[str2[i-k]]==0)
             m2.erase(str2[i-k]); //erase not --
        m2[str2[i]]++;
        if(m1==m2){
            cout<<"True";
            return 0;
        }
    }
  
    cout<<"false";
    return 0;

}