#include<iostream>
using namespace std;
struct Queue{
	int size;
	int* array;
	int last = -1;
	Queue(int s){
		size = s;
		array = new int[size];
	}
	~Queue() {
        delete[] array;
    }
};
bool put(Queue* q, int value){
    if(q->last < q->size - 1){
    	q->last += 1;
	    q->array[q->last] = value;
	    return true;
}
	cout<<"Queue overloaded\n";
	return false;	
}
bool pick(Queue* q){
	if(q->last != -1){
		int r = q->array[0];
		for(int i =0;i<= q->last;i++){			
			q->array[i] = q->array[i+1];			
		}
		q->last -=1;
		return true;
	}
	if(q->last == -1){\
	cout<<"Queue underloded\n";
	return false;
	}

}
int peek(Queue* q){
	if(q->last != -1){
		int r = q->array[0];
		return r;
	}
}

int main(){
	Queue q(100); //static
	Queue* p = new Queue(199);//dynamic
	put(p, 1);
	put(p, 10);
	put(p, 27);
	put(p, 20);
	pick(p);
	pick(p);
	pick(p);
	pick(p);
	pick(p);
	peek(p);
	
	
}
