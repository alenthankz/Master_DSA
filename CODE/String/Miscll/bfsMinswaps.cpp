#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i =0;i<n;i++) 
int fn(string A, string B){
    queue< pair< string ,pair< int ,int> > >q;
    q.push(make_pair(A,make_pair(0,0)));
    set<string>vis;
    while(!q.empty()){
        pair<string,pair<int,int> > p = q.front();q.pop();
        string curr = p.first;
        int idx = p.second.first;
        int level = p.second.second;
        int i;
        for( i =idx;i<B.size();i++){
            if(B[i]!=curr[i])break;
        }
        for(int j =i;j<B.size();j++){
            if(B[i]==curr[j]){
                swap(curr[i],curr[j]);
                if(B==curr)return level+1;
                if(!vis.count(curr)){                                     //set.count(val)!=0 is powerful 
                    q.push(make_pair(curr ,make_pair(i+1,level+1)));
                    vis.insert(curr);
                }
                swap(curr[i],curr[j]);
            }
        }
    }


}
int main(){
    string A="ALEN",B="ALNE";
    cout<<fn(A,B);


    return 0;
}