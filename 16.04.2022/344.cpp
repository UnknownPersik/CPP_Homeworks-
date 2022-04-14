#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int n, temp;
vector <pair<int, int>> point;
ifstream input("input.txt");
ofstream output("output.txt");

int main() {
    input >> n;
    for (int i = 0; i < n; i++) {
        input >> temp;
        pair <int, int> t{ temp, i + 1 };
        point.push_back(t);
    }
    sort(point.begin(), point.end());
    int min = point[1].first - point[0].first;
    int numberA = point[0].second;
    int numberB = point[1].second;
    for (int i = 2; i < n; i++) {
        if (min > point[i].first - point[i - 1].first) {
            min = point[i].first - point[i - 1].first;
            numberA = point[i - 1].second;
            numberB = point[i].second;
        }
        if (min == 1) 
            break;
    }
    output << min << endl;
    output << numberA << " " << numberB;
    return 0;
}
