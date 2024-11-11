#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Item {
	int value, weight;
	Item(int v, int w) : value(v), weight(w) {}
};

//comparator fn to sort items based on value-to-weight ratio
bool compare(Item a, Item b) {
	double ratio1 = (double)a.value / a.weight;
	double ratio2 = (double)b.value / b.weight;
	return ratio1 > ratio2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
	sort(items.begin(), items.end(), compare);
	double maxValue = 0.0;
	
	for(auto &item : items) {
		if(W >= item.weight) {
			W -= item.weight;
			maxValue += item.value;
		} else {
			maxValue += item.value * ((double)W / item.weight);
			break;
		}
	}
	return maxValue;
}

int main() {
	int W = 50; //knapsack capacity
	vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
	cout<<"Maximum value in Knapsack = "<< fractionalKnapsack(W, items)<<endl;
	return 0;
}