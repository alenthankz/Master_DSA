// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Node{
    public:
    char data;
    Node*next,*prev;
    Node(int val){
        data=val;
        next=prev=NULL;
    }
};

void appendNode(Node**head ,Node**tail,Node* temp){
    if(*head==NULL){
        *head=*tail=temp;
        return;
    }
    (*tail)->next=temp;
    temp->prev=*tail;
    *tail=temp;
}

void deleteNode(Node**head ,Node**tail,Node* temp){
    if(*head==temp)*head=(*head)->next;
    if(*tail==temp)*tail=(*tail)->prev;
    if(temp->next) temp->next->prev=temp->prev;
    if(temp->prev) temp->prev->next=temp->next;
}


string FirstNonRepeating(string A){
	Node *head =NULL;
	Node *tail=NULL;
	vector<Node*>darr(256,NULL);
	vector<int>repeated(256,0);
	string str="";
	for(int i =0;i<A.size();i++){
		char chr = A[i];
		int c =int(chr-'a');
		if(!repeated[c]){
			if(darr[c]==NULL){
				Node* temp =new Node(chr);
				appendNode(&head,&tail,temp);
				darr[c]=tail;
			}else{
				deleteNode(&head,&tail,darr[c]);
				darr[c]=NULL; repeated[c]=1;
			}
		}
		if(head!=NULL){
			str=str+head->data;
		}else{
			str=str+"#";
		}
	}
	return str;
	
}

// { Driver Code Starts.
int main(){
	
}  // } Driver Code Ends