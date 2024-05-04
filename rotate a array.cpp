#include<iostream>
using namespace std;
void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}
void rotate(int arr[],int k, int size){
    int sample_arr[size];
    copyArray(arr, sample_arr, size);
	k = k % size;
//	for(int i=0;i<size;i++){
//		cout<<sample_arr[i]<<"  ";
//	}
//	cout<<"\nthis is the nigga"<<endl;
//	cout<<"]"<<endl;
	for(int i =0;i<k;i++){
		int last = sample_arr[size-1];
		for(int j=size-1;j>0;j--){
			sample_arr[j] = sample_arr[j-1];
		}
		sample_arr[0] = last;

	}
	
	cout<<"[";
	for(int i=0;i<size;i++){
		cout<<sample_arr[i]<<"  ";
	}
	cout<<"]"<<endl;
}


// return a sliced array


int* slice_after(int arr[], int size, int from){
	int* r_arr = new int{size-from};
	if (from < 0){
		from = size + from;
	}
	int j=0;
	for(int i = from; i< size; i++){
		r_arr[j++] = arr[i];
	}
	
	return r_arr;
	
}
int* slice_before(int arr[], int size, int to){
	int* r_arr = new int{size-to};
	if(to < 0){
		to = to + size;
	}
	int j = 0;
	for(int i = 0; i < to; i++){
		r_arr[j++] = arr[i];
	}
	return r_arr;
}
//void rotate_this(int arr,int size,int k){
//	k = k % size;n
//	int* new_arr = new int{size};
//	for(int i=0;i<=)
//}

// in future i will make a slicing array function
int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6,7,8};
    for (int i = 0; i <= 10; i++) {
        rotate(arr, i, 7);
    }

    int to = -5;
    int size = 9;
    int *ptr = slice_before(arr, size, to);
    int sliced_size = (to >= 0) ? to : size + to;
    for (int i = 0; i < sliced_size; i++) {
        cout << ptr[i] << endl;
    }

    int from = -3;
    int usliced_size = -1*from;
    cout<<"nigga"<<endl;
    cout<<"This is "<<usliced_size<<endl;
    ptr = slice_after(arr,size, from);
    for (int i = 0; i < usliced_size; i++) {
        cout << ptr[i] << endl;
    }

    return 0;
}


