// A linked list is a series of connected nodes, where each node is connected to the next node.
// Each node on a linked list contains two parts; one is data part and second is next part (pointer).
// A linked list is called 'linked' because each node in the series has a pointer that points to the second node, 
// the second node points to the third node and so on.

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


	cout << "The list is: ";
	print();

	return 0;
}