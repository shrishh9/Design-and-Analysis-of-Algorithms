#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9; //large number to represent infinity

void floydWarshall(vector<vector<int>>& dist) {
int V = dist.size();

for(int k=0; k<V; k++) {
	for(int i=0; i<V; i++) {
		for(int j=0; j<V; j++){
			if (dist[i][k] < INF && dist[k][j] < INF) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
	        }
        }
    }
}

void printsol(const vector<vector<int>>& dist) {
	int V = dist.size();
	for(int i=0; i<V; i++) {
		for(int j=0; j<V; j++) {
			if (dist[i][j] == INF)
			cout << "INF" << "\t";
			else
			cout << dist[i][j] <<"\t";
		}
		cout<<endl;
	}
}
int main() {
	vector<vector<int>> graph = {
	{0,3,INF,7},
	{8,0,2,INF},
	{5,INF,0,1},
	{2,INF,INF,0}
	};
	
	floydWarshall(graph);
	cout<<"The shortest distance matrix is: "<<endl;
	printsol(graph);
	
	return 0;
}