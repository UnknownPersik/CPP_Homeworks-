#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

fstream input("INPUT.txt");
ofstream output("OUTPUT.txt");
int temp, difference;
int massiv[100000];

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
    int f = 0;
    int size = 0;
    if (!input) {
        cout << "Create file";
        return -1;
    }
    while (!input.eof()) {
        input >> temp;
        massiv[size] = temp;
        size++;
    }
    quickSort(massiv, size);
    difference = massiv[1] - massiv[0];
    for (int i = 2; i < size; i++) {
        if (difference != massiv[i] - massiv[i - 1]) {
            f = 0;
            break;
        }
        else
            f = 1;
            
    }
    if (f)
        output << "Yes";
    else
        output << "No";
    return 0;
}
