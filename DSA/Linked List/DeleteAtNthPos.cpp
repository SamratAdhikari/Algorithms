#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head = NULL;

void insert(int num){
	Node* temp = new Node;

	temp->data = num;
	temp->next = head;

	head = temp;

}

void deleteAtNth(int pos){
	Node* temp = head;

	if (pos == 0){
		head = temp->next;
		delete temp;
		return;
	}



	for (int i=0; i<pos-1; i++){
		temp = temp->next;
	}
	// temp->next = temp->next->next;
	// return;

	Node* temp1 = temp->next;
	temp->next = temp1->next;
	delete temp1;
}

void print(){
	Node* temp = head;

	while( temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main(){

	int pos, elem, num;

	cout << "Enter the number of elements: ";
	cin >> elem;

	for (int i=0; i<elem; i++){
		cout << "Enter the number: ";
		cin >> num;
		
		insert(num); 
	}

	cout << "Enter the position of the node for deletion: ";
	cin >> pos;

	deleteAtNth(pos);

	cout << "The List is: ";
	print();

	return 0;
}