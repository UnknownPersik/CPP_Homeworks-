#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");
int n, m;

int main() {
    if (!input) {
        cout << "Create file";
        return -1;
    }
    input >> m >> n;
    vector <long long> massiv(1 + n, 1);
    for (int i = m; i <= n; i++) {
        massiv[i] = massiv[i - 1] + massiv[i - m];
    }
    output << massiv[n];
    return 0;
}
