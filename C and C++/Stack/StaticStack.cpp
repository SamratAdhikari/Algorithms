// Array implementation of Stack

#include <iostream>
using namespace std;

#define size 5

struct Stack{
	int top = -1;
	int array[size];

	bool isEmpty();
	bool isFull();
	void push();
	void pop();
	void print();
};

bool Stack::isEmpty(){
	return (top == -1);

}

bool Stack::isFull(){
	return (top == size-1);

}


void Stack::push(){

	if (isFull()){
		cout << "Stack Overflow" << endl;
		return;
	}

	int num;
	cout << "Enter a number: ";
	cin >> num;

	array[++top]  = num;

	cout << "Item added to the stack" << endl;

}


void Stack::pop(){
	if (isEmpty()){
		cout << "Stack Underflow" << endl;
		return;
	}

	cout << "The popped item is " << array[top] << endl;
	top--;
}


void Stack::print(){
	if (isEmpty()){
		cout << "Stack is empty" << endl;
		return;
	}

	cout << "The items in the stack are: " << endl; 
	for (int i=top; i>=0; i--){
		cout << array[i] << " ";
	}
}


int main(){
	Stack obj;
	int choice;

	bool run = true;

		cout << "Choose one of the following options: " << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Display" << endl;
		cout << "4. Exit" << endl;

	while (run){
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch(choice){
		case 1:
			obj.push();
			break;

		case 2:
			obj.pop();
			break;

		case 3:
			obj.print();
			break;

		case 4:
			run = false;
			break;

		default:
			break;
		} 

	}


	system("pause");
	return 0;
}