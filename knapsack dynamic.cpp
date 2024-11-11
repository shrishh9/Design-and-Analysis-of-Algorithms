#include <iostream>
#include <vector>

using namespace std;

int knapsackDP(int W, const vector<int>& weights, const vector<int>& values) {
	int n = weights.size();
	vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
	
	for(int i=1; i<=n; ++i) {
		for(int j=0; j<=W; ++j) {
			if (weights[i-1] <= j) {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i-1]] + values[i-1]);
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][W];
}

int main() {
	int W = 50;
	vector<int> weights = {10, 20, 30};
	vector<int> values = {60, 100, 120};
	
	cout<< "Maximum value in knapsack = "<< knapsackDP(W, weights, values) <<endl;
	return 0;
}