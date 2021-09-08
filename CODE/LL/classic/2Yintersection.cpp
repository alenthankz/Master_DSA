#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; 

Node* detectCycle(Node *head1){
    Node * slow =head1,*fast=head1;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head1;
            while(slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;
            }
            return fast->next; //important: fast is the end of list after cycleremoval ,
            //  whereas fast->next = start/intersection point before cycle removal
        }
    }
}


int intersectPoint(Node* head1, Node* head2)
{
    Node* ptr2 = head2;
    while(ptr2->next){
        ptr2=ptr2->next;
    }
    ptr2->next=head1;
    return detectCycle(head2)->data;
}

int main(){

}