#include <iostream>
using namespace std;


struct Node{
	int data;
	Node* next;
};

Node* head = NULL; // empty list


void insert(int num){
	Node* temp = new Node;

	temp->data = num;
	temp->next = head;

	head = temp;
}

void append(int num){
	Node* temp = head;

	Node* newNode = new Node;
	newNode->data = num;
	newNode->next = NULL;

	if (head == NULL){
		head = newNode;
		return;
	}

	while (temp->next != NULL){
		temp = temp->next;
	}

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
	int num, elem;

	cout << "Enter the number of elements: ";
	cin >> elem;

	for (int i=0; i<elem; i++){
		cout << "Enter the element: ";
		cin >> num;

		insert(num);
	}

	append(69);


	cout << "The list is: ";
	print();

	return 0;
}