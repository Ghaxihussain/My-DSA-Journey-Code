#include<iostream>
#include<cstring>
#include<string>
using namespace std;
struct stack {
    int top = -1;
    int size = 100;
    string* arr;

    
    stack() {
        arr = new string[size]; 
    }

    
    ~stack() {
        delete[] arr; 
    }
};
bool pull(stack* st) {
    if (st->top == -1) {

        return false;
    }
    st->top -= 1;

    return true;
}

bool push(stack* st, string value) {
    if (st->top >= st->size) {

        return false;
    }
    st->top++;
    st->arr[st->top] = value;

    return true;
}
string peek(stack *st){
	return st->arr[st->top];
}

int isoperand(char c){
	switch(c){
		case '/':
        case '*':
        case '+':
        case '-':
        	return 0;
        default:
            return 1;
	}
}
string getinfix(string postfix){
	string infix;
	stack* st = new stack();
	for(int i = 0; postfix[i] != '\0'; i++){
		cout<<"h";
		if(isoperand(postfix[i])){
			string operand(1, postfix[i]);
			push(st, operand);
		}
		else{
			
			
			string op1 = peek(st);
            pull(st);
            string op2 = peek(st);
            pull(st);
            string op3 = "(" + op2 + postfix[i] + op1 + ")";
            push(st, op3);
		}
		
	}
	cout<<"Done"<<endl;
	infix = peek(st);
	return infix;
}
int main(){
    cout << getinfix("ab+d-") << endl;
    return 0;
}
