// here all index are of array only except sNode 
// we are actually just traversing the array only but along with it we change index of segment tree;
// MIN SEGMENT TREE

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> V;

int createSegTree(int * arr , V& sTree ,int st ,int en , int sNode){
    if(st==en){ sTree[sNode] = arr[st] ; return arr[st] ;}
    int mid =st+ (en-st)/2;
    sTree[sNode]=min( createSegTree(arr,sTree,st,mid,2*sNode+1) , createSegTree(arr,sTree,mid+1,en,2*sNode+2) );
    return sTree[sNode];
}

int query(V& sTree ,int st,int en ,int qst,int qen,int sNode){
    if(st>=qst && qen>=en){ return sTree[sNode];} //total overlap 
    if(qst>en || qen<st ) return INT_MAX;
    int mid =st+(en-st)/2;
    return min(query( sTree,st,mid,qst,qen,2*sNode+1), query(sTree,mid+1,en,qst,qen,2*sNode+2));
}

void update(int * arr, V&sTree,int st,int en ,int index,int val,int sNode){
    if(st==en){
        arr[index]=val;
        sTree[sNode]=val;
        return ;
    }
    int mid =st+(en-st)/2;
    if(index>=st && index<=mid){
        update(arr,sTree,st,mid,index,val,2*sNode+1);
    }else{
        update(arr,sTree,mid+1,en,index,val,2*sNode+2);
    }
    sTree[sNode]=min( sTree[2*sNode+1], sTree[2*sNode+2] );   
}


int main(){
    int n =10;
    int arr[10]={1,2,3,4,5,6,7,8,9,10};

    int x =(int)( ceil(log2(n)));
    int m =2* (int)pow(2,x) -1;
    V sTree(m ,0);

    createSegTree(arr,sTree,0,n-1,0);


    return 0;
}