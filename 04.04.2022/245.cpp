#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ofstream output("OUTPUT.txt");

int main()
{
    int n;
    int result = 0;
    ifstream inputFile("INPUT.txt");
    if (!inputFile) {
        cout << "Create file";
        return -1;
    }
    inputFile >> n;
    int* massiv = new int[n];
    for (int i = 0; i < n; i++)
    {
        inputFile >> massiv[i];
    }
    sort(massiv, massiv + n);
    if (n == 0)
        output << 0;
    if (n == 1) {
        output << massiv[0];
    }
    if (n == 2) {
        output << massiv[0] + massiv[1];
    }
    if (n > 2) {
        int top = n - 1;
        int last = n - 3;
        int sum = massiv[top] + massiv[top - 1];
        result = sum;
        while (last >= 0) {
            while (last >= 0 && massiv[last] + massiv[last + 1] < massiv[top]) {
                if (sum > result)
                    result = sum;
                sum -= massiv[top];
                top--;
                sum += massiv[last];
                last--;
            }
            if (last >= 0) {
                sum += massiv[last];
                if (sum > result)
                    result = sum;
                last--;
            }

        }
        output << result;
    }
}
