#include <fstream>
#include <iostream>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");
int n, temp;
char symbol;

int findMinimum(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

int main()
{

    int x = 0, y = 0, z = 0, min = 0;
    if (!input) {
        cout << "Create file";
        return -1;
    }
    input >> n;
    for (int i = 0; i < n; i++) {
        input >> symbol;
        if (symbol == 'X') {
            input >> temp;
            x += temp;
        }
        else if (symbol == 'Y') {
            input >> temp;
            x += temp;
            z += temp;
        }
        else {
            input >> temp;
            z += temp;
        }
    }
    if ((x > 0) && (z > 0))
        y = findMinimum(x, z);
    if ((x < 0) && (z < 0))
        y = findMinimum(x, z);
    x -= y;
    z -= y;
    output << x + y + z;
    return 0;
}
