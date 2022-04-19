#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");
int n;

int main() {
    if (!input) {
        cout << "Create file";
        return -1;
    }
    input >> n;
    if (n == 1){
        output << 0;
        return 0; 
    }
    vector <int> heightVal(n + 1);
    vector <int> heightDif(n + 1);
    vector <int> superJump(n + 1);
    vector <int> sumEnergy(n + 1);
    input >> heightVal[1] >> heightVal[2];
    if (n == 2) { 
        output << abs(heightVal[2] - heightVal[1]); 
        return 0; 
    }
    sumEnergy[2] = abs(heightVal[2] - heightVal[1]);
    for (int i = 3; i <= n;i++) {
        input >> heightVal[i];
        heightDif[i] = abs(heightVal[i] - heightVal[i - 1]);
        superJump[i] = 3 * abs(heightVal[i] - heightVal[i - 2]);
        sumEnergy[i] = min(sumEnergy[i - 2] + superJump[i], sumEnergy[i - 1] + heightDif[i]);
    }
    output << sumEnergy[n];
    return 0;
}
