// also done with .substr(start,count)
#include<bits/stdc++.h>
using namespace std;


int main(){
    // count of substrings of length k 
    int k =3;
    string str="abababab";

    deque<char>dq;
    map< deque<char> , int> mp;

    for(int i =0;i<k;i++)
        dq.push_back(str[i]);
    
    mp[dq]++;
    dq.pop_front();
    for(int i =k;i<str.size();i++){
        
        dq.push_back(str[k]);
        mp[dq]++;
        dq.pop_front();
    }
    int max =INT_MIN;
    deque<char>ans;
    for(map< deque<char>, int> ::iterator i =mp.begin();i!=mp.end();i++){
        if(i->second>max){
            max = i->second;
            ans = i->first;
        }
    }
    for(int i =0;i<ans.size();i++){
        cout<<ans[i];
    }
    cout<<endl;
    
    return 0;
}