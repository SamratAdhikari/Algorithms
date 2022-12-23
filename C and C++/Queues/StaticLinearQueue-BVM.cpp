#include<iostream>
#define size 5

using namespace std;


struct Queue{
	int array[size];
	int front = -1;
	int rear = -1;


	bool isEmpty();
	bool isFull();
	void enQueue();
	void deQueue();
	void print();
};


bool Queue::isEmpty(){
	return (front == -1 && rear == -1);
}

bool Queue::isFull(){
	return (rear == size-1);
}

void Queue::enQueue(){
	if (isFull()){
		cout << "Queue Overflow" << endl;
		return;
	}

	int num;
	cout << "Enter a number: ";
	cin >> num;

	if (isEmpty())
		front = 0;

	array[++rear] = num;
	cout << "The Data " << num << " added to the queue" << endl;
}


void Queue::deQueue(){
	if (isEmpty()){
		cout << "Queue Underflow" << endl;
		return;
	}

	if (front == rear){ // only one data
		rear = front = -1;
	}
	else{
		front++;
	}

	cout << "The dequeued item is " << array[front] << endl;
	cout << endl;
}

void Queue::print(){
	if (isEmpty()){
		cout << "Queue is empty" << endl;
		return;
	}

	for (int i=front; i<=rear; i++)
		cout << array[i] << " ";

	cout << endl;
}

int main(){
	Queue obj;
	int choice;

	bool run = true;

		cout << "Choose one of the following options: " << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Display" << endl;
		cout << "4. Exit" << endl;

	while (run){
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch(choice){
		case 1:
			obj.enQueue();
			break;

		case 2:
			obj.deQueue();
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
