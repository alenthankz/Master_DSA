#include<bits/stdc++.h>
using namespace std;

class minHeap{
    int size,capacity;
    vector<int>arr;

    public:
    minHeap(int cap){
        size=0;
        arr.resize(cap+1,INT_MAX);
        capacity=cap;
    }
    int p(int i)return (i/2);
    int l(int i)return (2*i);
    int r(int i)return (2*i+1);

    void insert(int val);
    void shiftUp(int idx);
    int extractMin();
    void shiftDown(int idx);

}

void minHeap::insert(int val){
    if(size==capacity)return;
    size++;
    arr[size]=val;
    shiftUp(size);
}

void minHeap::shiftUp(int idx){
    while( idx!=1 && arr[p(idx)]>arr[idx] ){
        std::swap(arr[idx],arr[p(idx)]);
        idx=p(idx);
    }
    return;
}

int minHeap::extractMin(){
    int val =arr[1];

    swap(arr[1],arr[size]);
    size--;
    shiftDown(1);

    
    return val;
}

void minHeap::shiftDown(int idx){
    int l =left(idx);
    int r =right(idx);
    int smallest =i;

    if(l<=size && arr[l]<arr[i] )smallest=l;
    if(r<=size && arr[r]<arr[smallest] )smallest=r;
    if(smallest!=idx) 
    {
        swap(&arr[i],&arr[smallest]);
        shiftDown(smallest);
    }
}

