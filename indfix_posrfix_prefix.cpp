#include<iostream>
#include<cstring>
#include<string>
using namespace std;
struct stack {
    int top = -1;
    int size = 100;
    char* arr;

    
    stack() {
        arr = new char[size]; 
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

bool push(stack* st, char value) {
    if (st->top >= st->size) {

        return false;
    }
    st->top++;
    st->arr[st->top] = value;

    return true;
}
char peek(stack *st){
	return st->arr[st->top];
}
int precedence(char c){
	
    switch (c) {
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
}
}
int isopr(char c){
	switch(c){
		case '/':
        case '*':
        case '+':
        case '-':
        	return 1;
        default:
            return 0;
	}
}
string infix_to_post(string s){
	string postfix;
	int i=0;
	stack* st = new stack();
	while(s[i] != '\0'){
		if (s[i] == '('){
			push(st, s[i]);
		}
		else if (s[i] == ')'){
			do{
				postfix += peek(st);
				pull(st);
				
			}
			while(peek(st) != '(');
			pull(st);
		}
		else if(!isopr(s[i])){
			postfix += s[i];
		}
		else{
			if(precedence(s[i]) <= precedence(peek(st))){
				while(precedence(s[i]) <= precedence(peek(st))){
					postfix += peek(st);
					pull(st);
				}
				push(st, s[i]);
			}
			else{
				push(st, s[i]);
			}
		}
		i++;
		}
		
		while(st->top != -1){
			postfix += peek(st);
		
			pull(st);
	
	}
	delete st; // Free memory allocated for stack
	return postfix;
}
string reverse(string s) {
    string r_string = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        r_string += s[i];
    }
    return r_string;
}


string infix_to_prefix(string s) {
    // Reverse the infix expression
    string reversedInfix = reverse(s);

    // Reverse the infix expression and replace '(' with ')' and vice versa
    for (int i = 0; i < reversedInfix.length(); ++i) {
        if (reversedInfix[i] == '(') {
            reversedInfix[i] = ')';
        } else if (reversedInfix[i] == ')') {
            reversedInfix[i] = '(';
        }
    }

    // Compute the postfix expression
    string postfix = infix_to_post(reversedInfix);

    // Reverse the postfix expression to obtain the prefix expression
    string prefix = reverse(postfix);
    return prefix;
}





int main() {
    cout << infix_to_prefix("a+(b*c)");
    return 0;
}

