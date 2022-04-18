#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");
int n, temp;
int massiv[1000000];

void quickSort(int* massiv, int size) {
    int i = 0;
    int j = size - 1;
    int middle = massiv[size / 2];
    do {
        while (massiv[i] < middle) {
            i++;
        }
        while (massiv[j] > middle) {
            j--;
        }
        if (i <= j) {
            int tmp = massiv[i];
            massiv[i] = massiv[j];
            massiv[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        quickSort(massiv, j + 1);
    }
    if (i < size)
        quickSort(&massiv[i], size - i);
}

int main()
{
    if (!input) {
        cout << "Create file";
        return -1;
    }
    input >> n;
    for (int i = 0; i < n; i++) {
        input >> temp;
        massiv[i] = temp;
    }
    quickSort(massiv, n);
    int min1 = massiv[0];
    int min2 = massiv[1];
    int max1 = massiv[n - 1];
    int max2 = massiv[n - 2];
    int max3 = massiv[n - 3];
    long long  f = (long long) min1 * min2 * max1;
    long long t = (long long) max1 * max2 * max3;
    if (f > t)
        output << f;
    else
        output << t;    
    return 0;
}
