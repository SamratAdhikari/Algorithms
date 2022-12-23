// A node in a Doubly Linked List contains 3 entities:
// prev - points to the previous Node 
// data - stores integer value 
// next - points to the next Node 

#include <iostream>
using namespace std;


struct Node{
	Node* prev;
	int data;
	Node* next;
};

Node* head = NULL;


void append(int num){
	Node* temp = head;

	Node* newNode = new Node;
	newNode->data = num;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (head == NULL){	
		head = newNode;
		return;
	}

	while (temp->next != NULL){
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->prev = temp;
}


void deleteAtNthPos(int pos){
	Node* toDelete = head;

	if (pos == 0){
		head = head->next;
		head->prev = NULL;

		delete toDelete;
		return;
	}

	for (int i=0; i<pos; i++){
		toDelete = toDelete->next;
	}
		toDelete->prev->next = toDelete->next;

		if (toDelete->next != NULL)
			toDelete->next->prev = toDelete->prev;

		delete toDelete;
}

void print(){
	Node* temp = head;
	while(temp != NULL){
		cout << temp->data << " ";

		temp = temp->next;
	}
}


int main(){
	append(1);
	append(2);
	append(3);
	append(4);
	append(5);

	cout << "the list is: ";
	print();
	cout << endl;
	cout << "the list is: ";
	deleteAtNthPos(4);
	print();


	return 0;
}