#include<bits/stdc++.h>

using namespace std;

class Node{
	public:
	int data;
	Node* next;
};

Node *rev(Node *head,int k){
	
	Node* current = head;  
    Node* next = NULL;  
    Node* prev = NULL;  
    int count = 0;  
  
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
      

    if (next != NULL)  
        head->next = rev(next, k);  
    return prev;  
}

void insert(Node **head,int v){
	Node *n=new Node();
	n->data=v;
	n->next=*head;
	*head=n;
}

void printList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout<<node->data<<" ";  
        node = node->next;  
    }  
}  

int main(){
	Node *head=NULL;
	int val;
	cout<<"Enter values and enter '-99' to end:\n";
	for(;;){
		cin>>val;
		if(val==-99)
		    break;
		else
		    insert(&head,val);    
	}
	cout<<"\nEnter k :";
	int k;
	cin>>k;
	cout<<"My current list is: ";
	printList(head);
	
	head=rev(head,k);
	cout<<"\nReversed Linked list: ";  
    printList(head);
	return 0;
}


/* OUTPUT ...
Enter values and enter '-99' to end:
5
3
4
1
7
8
2
-99

Enter k :3
My current list is: 2 8 7 1 4 3 5
Reversed Linked list: 7 8 2 3 4 1 5
*/
