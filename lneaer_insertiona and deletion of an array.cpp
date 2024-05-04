#include<iostream>
using namespace std;

// this was linear search
int search(int arr[], int size, int number){
	for(int i =0; i< size ; i++){
		if(arr[i] >= number){
			return i;
		}
	}
}
int insertion(int arr[], int* size, int capacity, int number){
	if(*size >= capacity){
		return 0;
	}

	int index = search(arr, *size, number);
	if(*size > index){	
		for(int i= *size; i >= index; i--){
			arr[i+1] = arr[i];
		}
		arr[index] = number;
		
	}
	else{
		arr[index] = number;
	}
	*size++;
	}

void deletion(int arr[], int index, int* size){
	for(int i = index; i < *size; i++){
		arr[i] = arr[i+1];
	}
	*size -= 1;
}


main(){
	int capacity=100, size = 10;
	int arr[capacity] = {1,2,3,4,5,6,13,17,19,100};
	insertion(arr, &size, capacity, 101);
	deletion(arr,1,&size);
	for(int i =0;i<= size; i++){
		cout<<arr[i]<<endl;
	}
	
}

