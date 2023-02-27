#include <iostream>
using namespace std;


struct Node{
	int data;
	Node* next;
};

Node* head = NULL;

void insertAtNthPos(int num, int pos){
	Node* newNode = new Node;
	newNode->data = num;

	if (pos == 0){
		newNode->next = head;
		head = newNode;
		return;
	}

	Node* temp = head;

	for(int i=0; i<pos-1; i++){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void print(){
	Node* temp = head;

	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}

}

int main(){
	int elem, num, pos;
	cout << "Enter the number of elements: ";
	cin >> elem;

	for (int i=0; i<elem; i++){
		cout << "Enter the position: ";
		cin >> pos;
		cout << "Enter the number: ";
		cin >> num;

		insertAtNthPos(num, pos);
	}

	cout << "The List is ";
	print();



	return 0;
}