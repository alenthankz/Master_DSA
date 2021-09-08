#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    Node* next;
    int data;
    Node(int dat){
        next=NULL;
        data=dat;
    }
};


Node * mergge(Node * a,Node *b){
    Node * result =NULL;
    if(a==NULL)return b;
    if(b==NULL)return a;

    if(a->data<=b->data){
        result=a;
        result->next=mergge(a->next,b);
    }else{
        result=b;
        result->next=mergge(a,b->next);
    }
    return result;
}

Node* mergeKLists(Node* arr[], int n)
{
    int last=n-1;
    // repeat until only one list is left
    while (last != 0) {
        int i = 0, j = last;
 
        // (i, j) forms a pair
        while (i < j) {
            // merge List i with List j and store
            // merged list in List i
            arr[i] = mergge(arr[i], arr[j]);
 
            // consider next pair
            i++, j--;
 
            // If all pairs are merged, update last
            if (i >= j)
                last = j;
        }
    }
 
    return arr[0];
}