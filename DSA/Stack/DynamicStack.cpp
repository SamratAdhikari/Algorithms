// Linked List implementation of Stack

#include <iostream>
using namespace std;


struct Stack{
	int data;
	Stack* next;
};

Stack* top = NULL;

void push(int num){
	Stack* newStack = new Stack;
	
	newStack->data = num;
	newStack->next = top;

	top = newStack;
}

void pop(){
	Stack* toDelete = top;

	top = top->next;

	delete toDelete;
}

void print(){
	Stack* temp = top;

	while (temp != NULL){
		cout << temp->data << endl;
		temp = temp->next;
	}
}


int main(){
	int elem, num;

	cout << "Enter the number of elements: ";
	cin >> elem;

	for (int i=0; i<elem; i++){
		cout << "Enter the number: ";
		cin >> num;
		push(num);
	}

	cout << "Before popping the top most element" << endl;
	print();

	pop();

	cout << "After popping the top most element" << endl;
	print();

	pop();

	cout << "After popping the top most element" << endl;
	print();

	return 0;
}