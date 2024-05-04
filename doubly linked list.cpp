#include<iostream>
using namespace std;

struct Node{
	int value;
	Node* next;
	Node* prev;
};
Node* insert_head(Node* head, int value){
	Node* newnode = new Node;
	newnode->value = value;
	newnode->prev = NULL;
	if(head == NULL){
		head = newnode;
		newnode->next = NULL;
		return head;
	}
	newnode->next = head;
	head->prev = newnode;
	head = newnode;
	return head;
}
Node* insert_after(Node* head, int index, int value){
    Node* newnode = new Node;
    newnode->value = value;
    Node* itr = head;
    for(int i = 0; i < index - 1 && itr != NULL; i++){
        itr = itr->next;
    }
    if(itr == NULL){
        cout << "Index out of range." << endl;
        return head; 
    }
    Node* after = itr->next; 
    itr->next = newnode; 
    newnode->prev = itr;
    if(after != NULL){
        after->prev = newnode; 
    }
    newnode->next = after; 
    return head;
}

Node* delete_index(Node* head, int index){
    Node* itr = head;
    
    if(index == 0){
    	Node* temp = head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }
        delete temp;
        return head;
	}
   
    for(int i = 0; i < index - 1 && itr != NULL; i++){
        itr = itr->next;
    }

    if(itr == NULL || itr->next == NULL){
        cout << "Index is out of range." << endl;
        return head;
    }

    Node* prev = itr;
    Node* to_delete = itr->next;
    Node* after = to_delete->next;
    
  
    prev->next = after;
    if(after != NULL){
        after->prev = prev;
    }
    

    delete to_delete;
    
    return head;
}


void tri(Node* head){
    Node* itr = head;
    while(itr != NULL){
        cout << itr->value << endl;
        itr = itr->next;
    }
    cout<<itr->prev->value;
}


main(){
	Node* head = NULL;
	head = insert_head(head, 10);
	head = insert_head(head, 11);
	head = insert_head(head, 12);
	head = insert_head(head, 13);
	head = insert_after(head, 2, 10009);
	head = insert_after(head, 3, 10001);
//	tri(head);
	cout<<"--------------\n"<<endl;
	head = delete_index(head, 0);
	tri(head);
}

