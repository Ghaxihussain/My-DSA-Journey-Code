//linked Lists
#include<iostream>
using namespace std;

struct Node{
	int value;
	Node* next;
};

Node* insertatbegin(Node* head, int value){
	Node* newnode = new Node;
	newnode->value = value;
	newnode->next = head;
	return newnode;
}

void trivaersal_linked(struct Node* head ){
	cout<<"Start"<<endl;
	while(head != NULL){
		cout<<&head<<"    "<<head<<"     ";
		cout<< head -> value<<endl;
		head = head->next;
	
	}
	cout<<"Stop"<<endl;
}

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

