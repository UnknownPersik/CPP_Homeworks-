#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

ofstream outputFile("OUTPUT.txt");

int main()
{
	int N, D;
	int max = -INFINITY;
	int k = 0;
	int c = 1;
	vector<int> massiv;
	vector<int> result;
	map<int, int> dict;
	ifstream inputFile("INPUT.txt");
	if (!inputFile) {
		cout << "Create file";
		return -1;
	}
	inputFile >> N >> D;
	for (int i = 0; i < N; i++) {
		int temp;
		inputFile >> temp;
		massiv.push_back(temp);
		dict[temp] = 0;
		result.push_back(temp);
	}
	sort(massiv.begin(), massiv.end(), greater<int>());
	for (int i = 0; i < massiv.size() - 1; i++) {
		for (int j = i; j < massiv.size(); j++) {
			if (massiv[i] - massiv[j] <= D) {
				k++;
			}
		}
		if (k > max)
			max = k;
		k = 0;
	}
	for (int i = 0; i < massiv.size(); i++) {
		if (c > max)
			c = 1;
		dict[massiv[i]] = c;
		c++;
	}
	outputFile << max << endl;
	for (int i = 0; i < massiv.size(); i++)
		outputFile << dict[result[i]] << " ";
}
