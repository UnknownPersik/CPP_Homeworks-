#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int begin;
	int end;
	int weight;
	bool operator<(const Node& e) const {
		return weight < e.weight;
	}
};

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> cities(n);
	for (int i = 0; i < n; ++i) {
		cities[i] = -1;
	}
	for (int i = 0; i < k; ++i) {
		int v;
		cin >> v;
		--v;
		cities[v] = i;
	}
	vector<Node> edges;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			Node node;
			cin >> node.weight;
			node.begin = i;
			node.end = j;
			edges.push_back(node);
		}
	}
	sort(edges.begin(), edges.end());
	int result = 0;
	for (int i = k; i < n; ++i) {
		int j = 0;
		while ((j < edges.size()) && (cities[edges[j].begin] < 0 || cities[edges[j].end] >= 0)) {
			++j;
		}
		cities[edges[j].end] = cities[edges[j].begin];
		result += edges[j].weight;
	}
	cout << result << endl;
	return 0;
}
