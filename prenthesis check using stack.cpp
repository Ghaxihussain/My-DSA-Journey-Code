#include<iostream>
#include<cstring>

// This program only works for the simple prentheses check, the next prgram 
//will check it in a much bettrer way




using namespace std;

struct stack {
    int top = -1;
    int size = 100;
    char* arr;

    // Constructor to initialize the array
    stack() {
        arr = new char[size]; // Dynamically allocate memory for the array
    }

    // Destructor to deallocate memory
    ~stack() {
        delete[] arr; // Deallocate memory for the array
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
bool in(char str[], char check){
	for(int i=0;i<=strlen(str);i++){
		if (str[i] == check){
		return i;}
	}
	return false;
}
bool check_more_than_one_prentheses(char str[]){
	stack* st = new stack();
	char open[] = "{([";
	char close[]= "})]";
	for(int i = 0;i<= strlen(str);i++){
		if (in(open,str[i])){
			push(st, str[i]);
		}
		if(in(close,str[i])){
			if(in(close,str[i]) != in(open, st->arr[st->top])){
				return false;
			}
			if(st->top == -1){
				return false;
			}
			pull(st);
		}
		
	}
	if(st->top == -1){
		return true;
	}
	return false;
}




bool checkprenthesis(char str[100]){
	stack* st = new stack();
	for (int i =0; i<= strlen(str); i++){   
		if (str[i] == '('){
			push(st, str[i]);
		}
		if (str[i] == ')'){
			bool check = pull(st);
			if (check == false){
				return check;
			}
		
	}
    }
    if (st->top == -1){
    	return true;
	}

	return false;
}
int main() {
    stack* st = new stack(); 
    cout<<checkprenthesis("({)}");
    cout<<check_more_than_one_prentheses("({)}");
}

