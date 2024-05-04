#include<iostream>
using namespace std;
// making a reverse linked list and stack

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
        return head; // Return unchanged list if index is out of range
    }
    Node* after = itr->next; // Save the next node after the insertion point
    itr->next = newnode; // Update next pointer of the previous node
    newnode->prev = itr; // Update prev pointer of the new node
    if(after != NULL){
        after->prev = newnode; // Update prev pointer of the node after the new node
    }
    newnode->next = after; // Update next pointer of the new node
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
    // Traverse to the node before the one to be deleted
    for(int i = 0; i < index - 1 && itr != NULL; i++){
        itr = itr->next;
    }
    
    // Check if the index is out of range
    if(itr == NULL || itr->next == NULL){
        cout << "Index is out of range." << endl;
        return head;
    }
    
    // Save pointers to the previous and next nodes
    Node* prev = itr;
    Node* to_delete = itr->next;
    Node* after = to_delete->next;
    
    // Update pointers to remove the node to be deleted
    prev->next = after;
    if(after != NULL){
        after->prev = prev;
    }
    
    // Delete the node
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

