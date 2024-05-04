// This is the code for stack

#include<iostream>
using namespace std;
struct stack{
	int size;
	int top=-1;
	int* arr;
};
// check if empty
int isempty(stack* ptr){
	if(ptr->top == -1){
		return 1;
	}
	return 0;
}
// checki if full
int isfull(stack* ptr){
	if(ptr->size -1 == ptr->top){
		return 1;
	}
	return 0;
}
// push tha element in the stack 
void push(stack* ptr,int value){
	if(ptr->size-1 > ptr->top){
	ptr->top += 1;
	ptr->arr[ptr->top] = value;
	cout<<"done"<<endl;
	}
	else{
		cout<<"the array is full"<<endl;
	}
	
}
// pull the element out of stack
void pull(stack* ptr){
	if(ptr->top == -1){
		cout<<"the stack is empty";
	}
	else{
		cout<<"   "<<ptr->arr[ptr->top]<<endl;
		ptr->top -= 1;
		
	}
}

// return the top without remvoing
int peak(stack* ptr){
	if(isempty(ptr)){
		cout<<"\nstack empty"<<endl;
		return 0;
	}
	else{
		return ptr->arr[ptr->top];
	}
}
main(){
	stack* a = new stack;	
	a->size = 10;
	a->arr = new int{a->size};
	if(isempty(a)){
		cout<<"Empty"<<endl;
	}
	else{
		cout<<"Not mt"<<endl;
	}
	for(int i=0;i<=10;i++){
		push(a, i+1-i*11);
	}
	for(int i=0;i<=10;i++){
		pull(a);
	}
	push(a, 10);
	push(a, 11);
	cout<<peak(a);
	
}

