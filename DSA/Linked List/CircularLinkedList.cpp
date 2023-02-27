#include <iostream>
using namespace std;


// circular
struct Node{
	int data;
	Node* next;
};

Node* head = NULL;

void append(int num){
	Node* newNode = new Node;

	newNode->data = num;

	if (head == NULL){
		newNode->next = newNode;
		head = newNode;
		return;
	}

	Node* temp = head;
	while (temp->next != head){
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->next = head;


}



void deleteAtNthPos(int pos){
	Node* temp = head;

	if (pos == 0){
		while (temp->next != head){
			temp = temp->next;
		}

		Node* toDelete = head;
		temp->next = head->next;
		head = head->next;

		delete toDelete;
		return;
	}

	for (int i=0; i<pos-1; i++){
		temp = temp->next;
	}

	Node* toDelete = temp->next;
	temp->next = toDelete->next;

	delete toDelete;
}

void print(){
	Node* temp = head;

	do{
		cout << temp->data << " ";
		temp = temp->next;

	}while(temp != head);
	cout << endl;
}

int main(){
	append(1);
	append(2);
	append(3);
	append(4);
	append(5);
	append(9);
	append(5);

	cout << "Before deletion: ";
	print();

	cout << "After deleting 0th Node: ";
	deleteAtNthPos(0);
	print();

	cout << "After deleting 2nd Node: ";
	deleteAtNthPos(2);
	print();


	return 0;
}