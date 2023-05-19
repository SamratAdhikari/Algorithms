#include <iostream>
using namespace std;


bool isSafe(int **arr, int x, int y, int n){
	if (x<n && y<n && arr[x][y]==1)
		return true;

	return false;
}

bool backtrack(int **arr, int x, int y, int n, int ** solnArr){
	
	// base condition
	if (x==n-1 && y==n-1){
		solnArr[x][y] = 1;
		return true;
	}


	if (isSafe(arr, x, y, n)){
		solnArr[x][y] = 1;

		if (backtrack(arr, x+1, y, n, solnArr)){
			return true;
		}

		if (backtrack(arr, x, y+1, n, solnArr)){
			return true;
		}

		// backtrack
		solnArr[x][y] = 0;
		return false;
	}

	return false;
}


int main(){

	int n;
	cout << "Enter dimension of matrix (nxn): ";
	cin >> n;

	int **arr = new int *[n];

	for (int i=0; i<n; i++){
		arr[i] = new int[n];
	}



	cout << "Enter the maze pattern: " << endl;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}



	int **solnArr = new int *[n];
	for (int i=0; i<n; i++){
		solnArr[i] = new int[n];

		for (int j=0; j<n; j++){
			solnArr[i][j] = 0;
		}
	}


	if (backtrack(arr, 0, 0, n, solnArr)){
		cout << "The solution pattern is: " << endl;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				cout << solnArr[i][j] << " ";
			}
			cout << endl;
		}
	}



	system("pause");
	return 0;
}