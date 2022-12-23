// to calculate the address of ith index in an array:
//  --------------------> B + i*(size of the datatype) 
// B: base address which is always in hexadecimal system
// if array is of type 'int', size of the datatype = 4


#include <iostream>
using namespace std;

#define size 10

struct Array{
	int count = -1;
	int array[size];

	bool isFull();
	bool isEmpty();
	void overtake(int num);
	void insert(int num, int pos);
	void append(int num);
	void deleteAtNthPos(int pos);
	void search(int num);
	void sort();
	void reverse();
	void print();
};




// Checks whether the array is full or not
bool Array::isFull(){
	return (count == size-1);
}


// Checks whether the array is empty or not
bool Array::isEmpty(){
	return (count < 0);
}


// Adds a value to the end of the array
void Array::append(int num){
	if (isFull()){
		cout << "Array overflow" << endl;
		return;
	}

	array[++count] = num;
}



// Adds a value to any position/index of the array
void Array::insert(int pos, int num){
	if (isFull()){
		cout << "Array overflow" << endl;
		return;
	}


	for (int i=count; i>=pos; i--){
		array[i+1] = array[i];
	}
	count++;
	array[pos] = num;
}



// Adds a value to the beginning of the array
void Array::overtake(int num){
	if (isFull()){
		cout << "Array overflow" << endl;
		return;
	}

	if (isEmpty()){
		append(num);
		return;
	}

	insert(0, num);
}



// Deletes a value from any position/index of the array
void Array::deleteAtNthPos(int pos){
	for (int i=pos; i<count; i++){
		array[i] = array[i+1];
	}
	count--;
}



// Searches and prints the index/location of the value if exists in the array
void Array::search(int num){
	bool isFound = false;
	for (int i=0; i<=count; i++){
		if (array[i] == num){
			cout << "Number found at index " << i << endl; 
			isFound = true;
		}
	}

	if (!isFound)
		cout << "Number not found" << endl;
}



// Arranges the array in ascending order
void Array::sort(){
	int temp;
	for (int i=0; i<=count; i++){
		for (int j=i+1; j<=count; j++){
			if (array[i] > array[j]){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp; 
			}
		}
	}
	
}



// Rearranges the array from last to first
void Array::reverse(){

	int temp = 0;
	for (int i=0; i<=count/2; i++){
		temp = array[i];
		array[i] = array[count-i];
		array[count-i] = temp;
	}

}



// Traverses & displays each element of the array 
void Array::print(){
	if (isEmpty()){
		cout << "Array is empty" << endl;
		return;
	}

	for (int i=0; i<=count; i++)
		cout << array[i] << " ";

}



// Good Ol' main function
int main(){
	Array obj;


	obj.overtake(1); // 1
	obj.overtake(0); // 0 1
	obj.insert(2, 3); // 0 1 3
	obj.insert(2, 2); // 0 1 2 3
	obj.append(9); // 0 1 2 3 9
	obj.append(7); // 0 1 2 3 9 7
	obj.insert(0, -1); // -1 0 1 2 3 9 7
	obj.insert(6, 66); // -1 0 1 2 3 9 66 7
	obj.append(77); // -1 0 1 2 3 9 66 7 77
	obj.overtake(-77); // -77 -1 0 1 2 3 9 66 7 77
	obj.overtake(-99); // -77 -1 0 1 2 3 9 66 7 77


	cout << "Before deletion: ";
	obj.print();
	cout << endl;

	obj.deleteAtNthPos(0);

	cout << "After deletion: ";
	obj.print();
	cout << endl;

	obj.search(3);
	obj.search(9);

	obj.sort();
	obj.print();
	cout << endl;

	obj.reverse();
	obj.print();
	cout << endl;

	return 0;
}