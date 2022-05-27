#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> cost (n+1, vector<int>(n+1));
  for (int i = 0; i < n; i++)
  	for (int j = i + 1; j <= n; j++)
    	cin >> cost[i][j];
  vector<int> bestCost(n+1, INF);
    bestCost[0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < i; j++)
    	bestCost[i] = min(bestCost[i], bestCost[j] + cost[j][i]);
  cout << bestCost[n];
  return 0;
}
