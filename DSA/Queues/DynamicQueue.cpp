// Linked List implementation of Queue


#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enQueue(int num){
	Node* newNode = new Node;
	newNode->data = num;

	newNode->next = NULL;

	if (front == NULL && rear == NULL){ // empty queue
		front = rear = newNode;
		return;
	}

	rear->next = newNode;
	rear = newNode;
}


void deQueue(){
	Node* toDelete = front;

	if (front == NULL){
		cout << "Queue underflow" << endl;
		return;
	}

	if (front == rear){
		front = rear = NULL;
	}
	else{
		front = front->next;
	}
	delete toDelete;
}


void print(){
	Node* temp = front;

	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}

int main(){

	enQueue(1);
	enQueue(2);
	enQueue(3);
	enQueue(4);
	enQueue(5);

	cout << "Before dequeuing: ";
	print();

	deQueue();

	cout << "After dequeuing: ";
	print();


	return 0;
}