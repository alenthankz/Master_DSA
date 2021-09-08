// LOGIC :
// iterating a vector AGAIN after making a map may give you result in o(n) !!!!








#include<bits/stdc++.h>
using namespace std;
//vector<int>intitialize{1,2,3,4,5};
// arr.insert(itrpos,val);
// arr.erase(stitr);
// arr.erase(stitr,enditr);
// arr.clear();
// itr =next(itr,4) ; prev(itr,4)
// arr.resize(n,val);
int main(){
    //taking groups of m from vec , then its end limit of for loop is i<=(n-m)
    vector< vector< pair<int,int> > >arr(100);
    arr[0].push_back(make_pair(1,2));
    arr[0].push_back(make_pair(3,4));
    arr[1].push_back(make_pair(5,6));
    arr[2].push_back(make_pair(7,8));
    arr.resize(3);
    for(int i =0;i<arr.size();i++){
        for(vector< pair<int,int> > :: iterator it =arr[i].begin();it!=arr[i].end();it++){
            cout<<it->first; //otherwise *it;
            cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}