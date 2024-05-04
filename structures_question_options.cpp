#include<iostream>
#include<strings.h>
using namespace std;

// This is the structure i created for the options
struct options{
	string a1;
	string a2;
	string  a3;
	int correctoption;
};
//This is the function  i created for printing the options
void printOptions(options option){
 	cout<<"1) "<<option.a1;
 	cout<<"2) "<<option.a2;
 	cout<<"3) "<<option.a3;
 }
 // This is the nested structure i created for the questions
struct question{
	string question;
	options option;	
};
//This is the function  i created for printing the question

void printQuestion(question q){
    cout<<"Q) "<< q.question;
    printOptions(q.option);
	}
// check the answers
void checkanswer(question q, int input){
	if ((q.option.correctoption)== input ){
		cout<<"Correct\n";
	}
	else{
		cout<<"Incorrect";
	}
}
main(){
	
	
}

