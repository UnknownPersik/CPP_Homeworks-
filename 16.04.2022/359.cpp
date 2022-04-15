#include <iostream>
#include <fstream>

using namespace std;

long long n;
ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");

int main() {
    if (!input) {
        cout << "Create file";
        return -1;
    }
    input >> n;
    long long position = (n * n + 1) / 2;
    output << (position - 1) / 9 * 10 + (position - 1) % 9 + 1;
    return 0;
}
