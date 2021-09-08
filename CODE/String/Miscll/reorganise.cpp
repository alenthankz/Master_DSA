#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i =0;i<n;i++) 


// Rearrange characters in a string such that no two adjacent are same
string fn(string str){
    priority_queue< pair<int,char> >pq;
    map<char,int>mp;
    int i =0;
    loop(i,str.size()){
        mp[str[i]]++;
    }
    for(map<char,int>:: iterator it =mp.begin();it!=mp.end();it++){
        pq.push(make_pair(it->second,it->first));
    }
    string ans ="";
    while(!pq.empty()){
        pair<int,char> p =pq.top();pq.pop();
        ans+=p.second;p.first--;
        if(!pq.empty()){
           pair<int,char>  p2 =pq.top();pq.pop();
           ans+=p2.second;p2.first--;
           if(p2.first)pq.push(p2);
           if(p.first)pq.push(p);

        }else{
            if(p.first) pq.push(p);
            break;
        }
    }
    if(pq.empty())return ans;
    else return"";


}
int main(){
    string str="AAAAA";
    cout<<fn(str);


    return 0;
}