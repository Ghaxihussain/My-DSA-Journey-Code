#include<iostream>
using namespace std;

struct Node{
	int value;
	Node* next;
};
Node* linear_insert(Node* head,int value){
	Node* newnode = new Node;
	newnode->value = value;
	newnode->next = NULL;
	Node* p = head;
	if(head == NULL) {
        head = newnode;
        return head;
    }
	while((p->next!=NULL)){
		
		p = p->next;
	}
	
	p->next = newnode;
	return head;
}
Node* insertviaindex(Node *head, int index, int value){
	Node* newnode = new Node;
	newnode->value = value;
	Node *p = head;
	int i =0;
	while(i != (index-1)){
	
	
		p = p->next;
		i++;
	}
	newnode->next = p->next;
	p->next = newnode;
}

Node* remove(Node* head, int value){
    
    while(head != NULL && head->value == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    Node* ptr = head;
    while(ptr != NULL && ptr->next != NULL){
        if(ptr->next->value == value){
            Node* temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
        }
        else {
            ptr = ptr->next;
        }
    }
    
    return head;
}

Node* deletehead(Node* head){
	Node* temp = head;
	head = head->next;
	delete temp;
	return head;
}

Node* deletelast(Node* head){
	if(head==NULL || head->next ==NULL){
		return 0;
	}
	Node* p = head;
	Node* prev;
	while(p->next != NULL){
		prev = p;
		p = p->next;
	}	
	prev->next = NULL;
	delete p;
}

Node* deleteAtIndex(Node* head, int index) {
    if (head == NULL || head->next == NULL) {
        return NULL; 
    }
    
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    int i = 0;
    Node* p = head;
    Node* after = head->next;
    while (i != index-1 && p->next != NULL) {
        p = p->next;
        after = after->next;
        i++;
    }   
    if (p->next == NULL) {
        return head; 
    }
    p->next = after->next;
    delete after;
    
    return head;
}

void trivaersal_linked(struct Node* head ){
	cout<<"Start"<<endl;
	int i=0;
	while(head != NULL){
		cout<< i<<"   "<<&head<<"    "<<head<<"     ";
		cout<< head -> value<<endl;
		head = head->next;
		i++;
	
	}
	cout<<"Stop"<<endl;
}

main(){
    Node* head = 	NULL;
    head = linear_insert(head, 11);
    head = linear_insert(head, 101);
    head = linear_insert(head, 11);
    head = linear_insert(head, 10);
    head = linear_insert(head, 111);
    insertviaindex(head, 2, 1001);
    insertviaindex(head, 4, -1);
    trivaersal_linked(head);
//    head = remove(head, 111);
//    head = remove(head, 11);
//    head = deletehead(head);
//    deletelast(head);
    head = deleteAtIndex(head, 3);
    trivaersal_linked(head);
}

