//linked Lists
#include<iostream>
using namespace std;
//Make a Node
struct Node{
	int value;
	Node* next;
};
// Make a function to insert a node at the biggening
Node* insertatbegin(Node* head, int value){
	Node* newnode = new Node;
	newnode->value = value;
	newnode->next = head;
	return newnode;
}
// Maje a function to print the linked list 
void trivaersal_linked(struct Node* head ){
	cout<<"Start"<<endl;
	while(head != NULL){
		cout<<&head<<"    "<<head<<"     ";
		cout<< head -> value<<endl;
		head = head->next;
	
	}
	cout<<"Stop"<<endl;
}
// Make a function to insert a node at the certain index
Node* insertatindex(Node* head, int index,  int data){
	Node* p = head;
	Node* newnode = new Node;
	newnode->value = data;
	
	int i =0;
	while(i != index-1){
		p = p->next;
		i++;
	}
	newnode->next = p->next;
	p->next = newnode;
	
}
// Make a function to insert a node at the end
Node *insertatend(Node *head, int value){
	Node *newnode = new Node;
	newnode->value = value;
	newnode->next = NULL;
	Node *p = head;
	while(p->next != NULL){
		p = p->next;
	}
	p->next = newnode;

	return head;
}
// Main Program
main(){
	Node * head = NULL;
	cout<<"insertion at the Bigining :- \n";
	head = insertatbegin(head, 10);
	head = insertatbegin(head, 11);
	head = insertatbegin(head, 12);
	head = insertatbegin(head, 12);
	head = insertatbegin(head, 17);
	head = insertatbegin(head, 19);
	head = insertatbegin(head, 100);
	head = insertatbegin(head, 62);
	trivaersal_linked(head);
	cout<<"Insertion at the index :- \n";
	insertatindex(head, 2, 10);	
	trivaersal_linked(head);
	cout<<"After insertion at the end :- \n";
	head = insertatend(head, 1000);
	trivaersal_linked(head);
	
	
}

