#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");
int n, temp;
int inputMassiv[1000];
int massivCounters[1000];

int main() {
    if (!input) {
        cout << "Create file";
        return -1;
    }
    input >> n;
    for (int i = 0; i < n;i++) {
        input >> temp;
        inputMassiv[i] = temp;
    }
    for (int i = 0;i < n; i++) {
        massivCounters[i] = 1;
        for (int j = 0;j < i; j++) {
            if (inputMassiv[j] < inputMassiv[i])
                massivCounters[i] = max(massivCounters[i], 1 + massivCounters[j]);
        }
    }
    int answer = massivCounters[0];
    for (int i = 0; i < n; i++)
        answer = max(answer, massivCounters[i]);
    output << answer;
    return 0;
}
