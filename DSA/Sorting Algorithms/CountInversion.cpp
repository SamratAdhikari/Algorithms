#include <iostream>
using namespace std;


long long merge(int arr[], int left, int mid, int right){
	long long inv = 0;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int a[n1];
	int b[n2];

	for (int i=0; i<n1; i++)
		a[i] = arr[left+i];

	for (int i=0; i<n2; i++)
		b[i] = arr[mid+i+1];


	int i=0, j=0, k=left;

	while (i<n1 && j<n2){
		if (a[i] <= b[j]){
			arr[k] = a[i];
			k++;
			i++;
		}

		else{
			arr[k] = b[j];
			
			// a[i] > b[j] and i < j
			inv += n1 - i;

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
		arr[k] = a[j];
		k++;
		j++;
	}


	return inv;
}


long long mergeSort(int arr[], int left, int right){
	long long inv = 0;

	if (left < right){
		int mid = (left+right) / 2;

		inv += mergeSort(arr, left, mid);
		inv += mergeSort(arr, mid+1, right);
	
		inv += merge(arr, left, mid, right);
	}

	return inv;

}

int main(){
	int n;

	cout << "Enter the number of elements: ";
	cin >> n;
	int arr[n];

	cout << "Enter the data: " << endl;
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}
	cout << mergeSort(arr, 0, n-1);

	return 0;
}