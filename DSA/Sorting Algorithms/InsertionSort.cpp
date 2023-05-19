/*
In (n-1) passes, the array is sorted. 
First data is supposed to be sorted initially.
*/

#include <iostream>
using namespace std;

int main(){

	int n;
	cout << "Enter number of elements: ";
	cin >> n;

	int arr[n];

	for (int i=0; i<n; i++){
		cout << "Enter the data: ";
		cin >> arr[i];
	}


	for (int i=1; i<n; i++){
		int current = arr[i];
		int j = i-1;

		while (arr[j] > current && j >=0){
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = current;
	}


	cout << "The sorted data is: ";

	for (int i=0; i<n; i++){
		cout << arr[i] << " ";
	}

	cout << endl;


	system("pause");
	return 0;
}