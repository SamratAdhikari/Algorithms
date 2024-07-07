#include <iostream>
using namespace std;

int main(){

	int N, i, j, k, t;
	cin >> t;

	for (k=0; k<t; k++){

		// input
		cin >> N;

		int A[N], B[N];

		for (i=0; i<N; i++){
			cin >> A[i];
		}

		for (i=0; i<N; i++){
			cin >> B[i];
		}

		// processing
		i = 0;
		while (i < N && A[i] == B[i]){
			i++; 
		}

		j = N-1;
		while (j >=0 && A[j] == B[j]){
			j--;
		}

		// output
		cout << j - i + 1 << endl;
	}

	return 0;
}
