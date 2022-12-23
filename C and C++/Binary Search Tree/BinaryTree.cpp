#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left = NULL;
	Node* right = NULL;


	Node* createLeaf(int num);
	void addLeaf(int num, Node* Ptr);
	void printInOrder(Node* Ptr);
	Node* returnNode(int num, Node* Ptr);
};

Node* root = NULL;


Node* Node::createLeaf(int num){
	Node* newNode = new Node;
	newNode->data = num;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void Node::addLeaf(int num, Node* Ptr){
	if (root == NULL){
		root = createLeaf(num);
		return;
	}

	if (num < Ptr->data){ // left
		if (Ptr->left != NULL)
			addLeaf(num, Ptr->left);

		else
			Ptr->left = createLeaf(num);

	}

	else if (num > Ptr->data){ // right
		if (Ptr->right != NULL)
			addLeaf(num, Ptr->right);

		else
			Ptr->right = createLeaf(num);
	}

	else{
		cout << "The data " << num << " already exists in the tree" << endl;
	}
}



void Node::printInOrder(Node* Ptr){
	if (root == NULL){
		cout << "The tree is empty" << endl;
		return;
	}

	if (Ptr->left != NULL){
		printInOrder(Ptr->left);
	}
	cout << Ptr->data << " ";

	if (Ptr->right != NULL){
		printInOrder(Ptr->right);
	}

}




Node* Node::returnNode(int num, Node* Ptr){
	if (Ptr != NULL){
		if (Ptr->data == num)
			return Ptr;
		
		if (num < Ptr->data)
			return returnNode(num, Ptr->left);

		else if (num > Ptr->data)
			return returnNode(num, Ptr->right);
	}

	
	return NULL;
}




int main(){
	int TreeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
	Node obj;

	cout << "Before adding numbers" << endl;
	obj.printInOrder(root);

	cout << endl;
	for (int i=0; i<16; i++)
		obj.addLeaf(TreeKeys[i], root);

	cout << endl;
	cout <<"After adding numbers" << endl;
	obj.printInOrder(root);

	cout << endl;

	obj.returnNode(2, root);

	system("pause");
	return 0;
}