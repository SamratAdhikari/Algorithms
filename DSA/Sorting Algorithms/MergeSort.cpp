/*
Divide and Conquer algorithm
*/


#include <iostream>
using namespace std;


void merge(int arr[], int left, int mid, int right){
	int n1 = mid-left+1;
	int n2 = right - mid;

	// temp arrays
	int a[n1];
	int b[n2];

	for (int i=0; i<n1; i++){
		a[i] = arr[left+i];
	}

	for (int i=0; i<n2; i++){
		b[i] = arr[mid+1+i];
	}

	int i=0;
	int j=0;
	int k=left;

	while(i<n1 && j<n2){
		if (a[i] < b[j]){
			arr[k] = a[i];
			k++;
			i++;
		}

		else {
			arr[k] = b[j];
			k++;
			j++;
		}
	}

	while (i < n1){
		arr[k] = a[i];
		k++;
		i++;
	}

	while (j < n2){
		arr[k] = b[j];
		k++;
		j++;
	}


}



void mergeSort(int arr[], int left, int right){
	if (left < right){
		int mid = (left + right) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
	
		merge(arr, left, mid, right);
	}
}


int main(){

	int arr[] = {5, 7, 3, 2, 1};
	mergeSort(arr, 0, 4);


	cout << "The sorted data are: ";
	for (int i=0; i<5; i++){
		cout << arr[i] << " ";
	}
	cout << endl;


	return 0;
}