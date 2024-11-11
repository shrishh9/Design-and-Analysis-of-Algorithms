#include<iostream>
#include <vector>
#include<queue>

using namespace std;

int optimalMergeCost(const vector<int>& files) {
	//create a min heap
	priority_queue<int, vector<int>, greater<int>> minHeap(files.begin(), files.end());
	
	int totalcost = 0;
	
	//repeat untill only one file remains
	while(minHeap.size()> 1){
		//extract two smallest files
		int first = minHeap.top();
		minHeap.pop();
		int second = minHeap.top();
		minHeap.pop();
		
		//merge two files and add total cost
		int mergecost = first+second;
		totalcost += mergecost;
		
		//insert merged file back into minheap
		minHeap.push(mergecost);
	}
	return totalcost;
}

int main() {
	vector<int> files = { 5, 10, 15, 20
	};
	int minimumcost = optimalMergeCost(files);
	cout<<" minimum cost to merge all files: "<<minimumcost<<endl;
	
	return 0;
}