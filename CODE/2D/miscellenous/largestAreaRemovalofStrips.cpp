//Largest area possible after removal of a series of horizontal & vertical bars

#include<bits/stdc++.h>
using namespace std;

int largestArea(int * h , int * v, int H ,int V ,int M ,int N){
    set<int> s1;
    set<int> s2;
    for(int i =1;i<=N+1;i++)s1.insert(i);
    for(int i =1;i<=M+1;i++)s2.insert(i);

    for(int i =0;i<H;i++)  s1.erase(h[i]);
    for(int i =0;i<V;i++)  s2.erase(v[i]);

    vector<int>l1(s1.size());
    vector<int>l2(s2.size());

    for(set<int> ::iterator it = s1.begin();it!=s1.end();it++) l1.push_back(*it);
    for(set<int> ::iterator it = s2.begin();it!=s2.end();it++) l2.push_back(*it);

    sort(l1.begin(),l1.end());
    sort(l2.begin(),l2.end());
    int maxH=INT_MIN,maxV=INT_MIN,prev=0;
    
    for(int i =0;i<l1.size();i++){
        maxH = max(maxH , (l1[i]-prev) );
        prev = l1[i];
    }
    prev=0;
    for(int i =0;i<l2.size();i++){
        maxV = max(maxV , (l2[i]-prev) );
        prev = l2[i];
    }

    return (maxH * maxV);

}

int main(){

    int N = 3, M = 3;
    int h[] = { 2 };
    int v[] = { 2 };
    
    int H = sizeof(H) / sizeof(h[0]);
    int V = sizeof(V) / sizeof(v[0]);
    cout<<largestArea(h,v,H,V,M,N);
}