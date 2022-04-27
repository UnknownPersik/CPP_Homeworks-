#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");
int n;

int main()
{
    if (!input) {
        cout << "Create file";
        return -1;
    }
    int m = 1;
    int x = 0, y = 0;
    input >> n;
    vector <vector<int>> matrix = vector<vector<int>>(n, vector<int>(n, 0));
    matrix[0][0] = 1;
    while (m < n * n) {
        while (y < n - 1 && matrix[x][y + 1] == 0 && m < n * n) {
            y++;
            m++;
            matrix[x][y] = m;
        }
        while (x < n - 1 && matrix[x + 1][y] == 0 && m < n * n) {
            x++;
            m++;
            matrix[x][y] = m;
        }
        while (y > 0 && matrix[x][y - 1] == 0 && m < n * n) {
            y--;
            m++;
            matrix[x][y] = m;
        }
        while (x > 0 && matrix[x - 1][y] == 0 && m < n * n) {
            x--;
            m++;
            matrix[x][y] = m;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            output << matrix[i][j] << " ";
        output << endl;
    }
    return 0;
}
