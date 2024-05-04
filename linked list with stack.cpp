#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

int isempty(Node* top){
    if(top == NULL){
        return 1;
    }
    return 0;
}

Node* push(Node* top, int value){
    Node* newnode = new Node;
    newnode->value = value;
    
    if(isempty(top)){
    	top = newnode;
		top->next = NULL;        
        return top;
    }
    
    newnode->next = top;
    top = newnode;
    return top;
}


int pull(Node *&top){
    if(isempty(top)){
        cout << "Empty ";
        return -1;
    }
    else{
        Node* x = top;
        top = top->next;
        int y = x->value;
        delete x;
        return y;
    }
}
int peek(Node* top){
	cout<<top->value;
}
void tri(Node* h){
    Node* p = h;
    while(p != NULL){
        cout<<p->value<<endl;
        p = p->next;
    }
}

int main(){
    Node* t = NULL;
    t = push(t, 10);
    t = push(t, 11);
    t = push(t, 119);
    t = push(t, 12);
//    pull(t);
    pull(t);
    pull(t);
    pull(t);
    pull(t);
    cout<<"Value:- \n";
    peek(t);
    return 0;
}

