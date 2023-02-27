// Operations in Linked List

#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

// global variable, head points to the beginning of the list
Node* head = NULL; // empty list


// Insert at the beginning
void overtake(int num){
    Node* newNode = new Node;
    newNode->data = num;
    newNode->next = head;
    head = newNode;
}


// Insert at any specified position
void insert(int num, int pos){
    if (pos == 0){
        overtake(num);
        return;
    }
    
    Node* newNode = new Node;
    newNode->data = num;

    Node* temp = head;
    for(int i=0; i<pos-1; i++){
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}


// Insert at the end of the list
void append(int num){
    Node* temp = head;
    Node* newNode = new Node;
    
    newNode->data = num;
    newNode->next = NULL;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = newNode;
}


// Delete a node from any specified position
void deleteAtNthPos(int pos){
    Node* temp = head;
    
    if (pos == 0){
        head = head->next;
        delete temp;
        return;
    }
    
    for (int i=0; i<pos-1; i++){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}


// Traverse through the list and print all the data;
void print(){
    Node* temp = head;
    
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    cout << endl;
}


int main() {
    
    overtake(1);
    overtake(0);
    append(2);
    append(3);
    append(4);
    append(5);
    insert(7, 2);
    insert(77, 6);
    
    cout << "Before deletion: ";
    print();
    
    deleteAtNthPos(0);
    cout << "After deletion: ";
    print();
    deleteAtNthPos(5);
    print();
    
    system("pause");
    return 0;
}