#include<iostream>
using namespace std;
struct Node{
	int value;
	Node* next;
};

// insertion after
Node* linear_insert(Node* head, int value){
    Node* newnode = new Node;
    newnode->value = value;
    newnode->next = NULL;

    if(head == NULL){
    	cout<<"headnull"<<endl;
        head = newnode;
        head->next = head; // Circular link to itself
        return head;
    }

    Node* p = head;
    while(p->next != head){
        p = p->next;
    }
    p->next = newnode;
    newnode->next = head;
    return head;
}
// insert after a node
Node* insert_index(Node* head, int index, int value){
	Node* newnode= new Node;
	
	newnode->value =value;
	if (index == 0){
		Node* last_node = head;
		while (last_node->next != head){
			last_node = last_node->next;
		}
		newnode->next = head;
		head = newnode;
		last_node->next = head;
		return head;
	}
	Node* p =head;
	for (int i =0;i<index-1; i++){
		p = p->next;
	}
	newnode->next = p->next;
	p->next = newnode;
	return head;
}

// insert after
//print
void tri(Node* head){
    Node* p = head;
    int i = 0;
    do {
        cout << i << "   " << p->value << endl;
        p = p->next;
        i++;
    } while(p != head);
}

int main(){
    Node* head = NULL;
    
    head = linear_insert(head, 10);
   
    linear_insert(head, 120);
    linear_insert(head, 110);
    linear_insert(head, 90);
    linear_insert(head, 70);
    linear_insert(head, 40);
    tri(head);
    cout << "After insertions:" << endl;
  // Update head with the return value
    head = insert_index(head, 0, 10001);
     head = insert_index(head, 3, 100012);
    tri(head);
    return 0;
}



