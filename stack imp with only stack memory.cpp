#include<iostream>
using namespace std;

struct stack{
    int arr[100];
    int top;
};

int isempty(stack st){
    if(st.top == -1){
        return 1;
    }
    return 0;
}

void pop(stack& st){
    if(!isempty(st)){
        st.top--;
    }
    else{
        cout<<"The stack is empty"<<endl;
    }
}

void push(stack& st, int value){
    if(st.top == 99){
        cout<<"The stack is full. Cannot push more elements."<<endl;
        return;
    }
    st.top++;
    st.arr[st.top] = value;
}
void gettop(stack& st){
	cout<<st.arr[st.top];
}
int main(){
    stack st;
    st.top = -1;

    push(st, 10);
//    pop(st); // Remove the last pushed element
    gettop(st);
    return 0;
}

