#include<bits/stdc++.h>
using namespace std;


// advantage for letters are we can hash them using array 

// Check if frequency of all characters can become same by one removal

#define M 26

bool isSame(int freq[] ){
    int flag=1;
    int same=0;
    for(int i =0;i<M;i++){
        if(!freq[i])continue;
        if(flag){
            same=freq[i];
            flag=0;
        }
        if(freq[i]!=same)return false;
    }
    return true;
}

bool isPossible(string str){
    int freq[M]={0};
    for(int i=0;str[i]!='\0';i++){
        freq[str[i]]++;
    }
    if(isSame(freq))return true;

    for(int i =0;str[i]!='\0';i++){
        freq[str[i]]--;
        if(isSame(freq))return true;
        freq[str[i]]++;
    }
    return false;
}


int main(){
  
    return 0;
}
