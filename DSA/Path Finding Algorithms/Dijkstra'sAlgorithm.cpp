#include <iostream>
using namespace std;

#define INF 999

// vertices (v)
int V, src, cost[100][100];
int dist[100], parent[100];
bool visited[100] = {false};


void init(){
	for (int i=0; i<V; i++){
		dist[i] = INF;
		parent[i] = i;
	}

	dist[src] = 0;
}


int getNearest(){
	int minValue = INF;
	int minNode = 0;

	for(int i=0; i<V; i++){
		if (!visited[i] && dist[i] < minValue){
			minValue = dist[i];
			minNode = i;
		}
	}

	return minNode;
}


void dijkstra(){
	for (int i=0; i<V; i++){
		int nearest = getNearest();
		visited[nearest] = true;

		for (int adj=0; adj<V; adj++){
			if (cost[nearest][adj] != INF && dist[adj] > dist[nearest]+cost[nearest][adj]){
				dist[adj] = dist[nearest]+cost[nearest][adj];
				parent[adj] = nearest;
			}
		}
	}
}


void display(){
	cout << "Node: \t\t\t Cost : \t\t Path" << endl; 

	for (int i=0; i<V; i++){

		cout << i << "\t\t\t" << dist[i] << "\t\t\t" << " ";

		cout << i << " ";
		int parNode = parent[i];

		while (parNode != src){
			cout << " <- " << parNode << " ";
			parNode = parent[parNode];
		}  

		cout << endl;
	}
}



int main(){
	cout << "Enter the number of vertices: ";
	cin >> V;

	for (int i=0; i<V; i++){
		cout << "\nFrom node " << i << endl;  
		for (int j=0; j< V; j++){
			cout << "Enter the weight for node " << j << endl;
			cin >> cost[i][j];
		}
	}

	cout << "Enter the source vertex: ";
	cin >> src; 


	init();
	dijkstra();
	display();

	system("pause");
	return 0;
}







/*
	here, INF = 999 means the nodes are not connected to each other! 


	|	0 		1 		2 		3 		4 		5  		6 		7 		8
----+----------------------------------------------------------------------	
0 	|	0       4       999     999     999     999     999     8       999
1 	|	4       0       8       999     999     999     999     8       999
2 	|	999     8       0       7       999     4       999     999     2
3 	|	999     999     7       0       9       14      999     999     999
4 	|	999     999     999     9       0       10      999     999     999
5 	|	999     999     4       14      10      0       2       999     999
6 	|	999     999     999     999     999     2       0       1       6
7 	|	8       11      999     999     999     999     1       0       7
8 	|	999     999     2       999     999     999     6       7       0

*/



/*
0 		4       999     999     999     999     999     8       999
4       0       8       999     999     999     999     8       999
999     8       0       7       999     4       999     999     2
999     999     7       0       9       14      999     999     999
999     999     999     9       0       10      999     999     999
999     999     4       14      10      0       2       999     999
999     999     999     999     999     2       0       1       6
8       11      999     999     999     999     1       0       7
999     999     2       999     999     999     6       7       0

*/