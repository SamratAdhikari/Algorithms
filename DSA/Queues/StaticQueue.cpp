   // Array implementation of Queue

#include <iostream>
using namespace std;
#define size 10

struct Queue{
	int array[size];
	int front = -1;	
	int rear = -1;

	bool isEmpty();
	bool isFull();
	void enQueue(int num);
	void deQueue();
	void print();

};

bool Queue::isEmpty(){
	return (front == -1 && rear == -1);
}

bool Queue::isFull(){
	return (rear+1) % size == front;
}

void Queue::enQueue(int num){
	if (isFull()){
		cout << "Queue overflow" << endl;
		return;
	}

	if (isEmpty()){
		front = rear = 0;
	}

	else{
		rear = (rear+1) % size;
	}
	
	array[rear] = num;

}


void Queue::deQueue(){
	if (isEmpty()){
		cout << "Queue underflow" << endl;
		return;
	}

	if (front == rear){ // only one data
		rear = front = -1;
	}
	else{
		front = (front+1) % size;
	}
}

void Queue::print(){
	if (isEmpty()){
		cout << "Queue is empty" << endl;
		return;
	}

	int count = (rear + size - front) % size + 1;

	for (int i=0; i<count; i++){
		int index = (front+i) % size;
		cout << array[index] << " "; 
	}
	cout << endl;
}


int main(){

	Queue obj;

	obj.enQueue(1);
	obj.enQueue(2);
	obj.enQueue(3);
	obj.enQueue(4);
	obj.enQueue(5);

	cout << "Before dequeuing: " << endl;
	obj.print();

	obj.deQueue();

	cout << "After dequeuing: " << endl;
	obj.print();


	return 0;
}


