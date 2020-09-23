#include <bits/stdc++.h>

using namespace std;

class Node{
	public:
	int data;
	Node *next;
};

Node* XOR(Node *a,Node *b)  
{  
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));  
} 

void ins_frnt(Node **head,int val){
	
	Node *newn = new Node();
	newn->data=val;
	
	newn->next= (*head);
	
	if (*head != NULL)  
    {
	    (*head)->next = XOR(newn, (*head)->next);
	}
	
	*head=newn;
}

void ins_end(Node** head, int val){
    if(*head == NULL){
        *head = new Node();
        (*head)->data = val;
        return;
    }

    Node* newn = new Node();
    newn->data = val;

    Node* curr = *head;
    Node* prev = NULL;
    Node* nex = XOR(prev, curr->next);
    while (nex != NULL)
    { 
        prev = curr;
        curr = nex;
        nex = XOR(prev, curr->next);
    }
    newn->next = curr;
    curr->next = XOR(prev, newn);
}

void printList (Node *head)  
{  
    Node *curr = head;  
    Node *prev = NULL;  
    Node *nex;  
  
    cout << "Nodes of Linked List: \n";  
  
    while (curr != NULL)  
    {   
        cout<<curr->data<<" ";   
        nex = XOR (prev, curr->next);   
        prev = curr;  
        curr = nex;  
    }  
}

int main ()  
{  
    Node *head = NULL;  
    ins_frnt(&head, 5);  
    ins_frnt(&head, 10);  
    ins_frnt(&head, 15);  
    ins_frnt(&head, 20);  
    ins_frnt(&head, 25);
    ins_frnt(&head, 30);
    ins_end(&head, 1);
    ins_end(&head, 2);
    ins_end(&head, 3);
    printList (head);  
  
    return (0);  
}  

