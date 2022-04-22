#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");
int n, k;
int maxIndex = 0;
int firstIndex = -1;
int secondIndex = -1;
int firstAnswerIndex = -1;
int secondAnswerIndex = -1;
int minIndex = INT_MAX;

int main()
{
    input >> n >> k;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++) {
        vector <int> prov(k);
        for (int j = 0; j < k; j++) {
            input >> prov[j];
        }
        matrix.push_back(prov);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (matrix[i][j] > maxIndex) {
                maxIndex = matrix[i][j];
                firstIndex = i;
                secondIndex = j;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        if (matrix[firstIndex][i] < minIndex) {
            minIndex = matrix[firstIndex][i];
            firstAnswerIndex = i;
        }
    }
    minIndex = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (matrix[i][secondIndex] < minIndex) {
            minIndex = matrix[i][secondIndex];
            secondAnswerIndex = i;
        }
    }
    output << matrix[secondAnswerIndex][firstAnswerIndex];
    return 0;
}
