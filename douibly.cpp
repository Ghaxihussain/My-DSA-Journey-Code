#include<iostream>
using namespace std;
struct Node{
	int value;
	Node* prev;
	Node* next;
};
Node* insert_head(Node* head, int value){
	Node* newnode = new Node;
	Node* p = head;
	newnode->next = head;
	head = newnode->next;
	newnode->prev = NULL;
	return head;
}
void tri(Node* head){
	Node* p = head;
	int i = 0;
	while(p != NULL){
		cout<<i<<"   "<<p->value<<endl;
		p = p->next;
		i++;
	}
	
}

main(){
	Node* head;
	head = inser_thead
}

