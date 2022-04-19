#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> resultMatrix;
vector<vector<int> > inputMatrix, sumMatrix;
int n;

void solve()
{
    sumMatrix[0][0] = inputMatrix[0][0];
    for (int i = 1; i < n; i++)
    {
        sumMatrix[0][i] = inputMatrix[0][i] + sumMatrix[0][i - 1];
        resultMatrix[0][i] = 'l'; // l - less
        sumMatrix[i][0] = inputMatrix[i][0] + sumMatrix[i - 1][0];
        resultMatrix[i][0] = 'u'; // u - upper
    }
    resultMatrix[0][0] = 'i';
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            sumMatrix[i][j] = inputMatrix[i][j];
            if (sumMatrix[i - 1][j] < sumMatrix[i][j - 1])
            {
                sumMatrix[i][j] += sumMatrix[i - 1][j];
                resultMatrix[i][j] = 'u';
            }
            else
            {
                sumMatrix[i][j] += sumMatrix[i][j - 1];
                resultMatrix[i][j] = 'l';
            }
        }
    int x = n - 1, y = n - 1;
    bool isEnd = false;
    do
    {
        int X = x, Y = y;
        if (resultMatrix[x][y] == 'u')
            x--;
        else if (resultMatrix[x][y] == 'l')
            y--;
        else if (resultMatrix[x][y] == 'i')
            isEnd = true;
        resultMatrix[X][Y] = '#';
    } while (!isEnd);
}

int main()
{
    cin >> n;
    inputMatrix = vector<vector<int>> (n, vector<int>(n, 0));
    sumMatrix = vector<vector<int>> (n, vector<int>(n, 0));
    resultMatrix = vector<string> (n, string(n, '-'));
    char c;
    for (int i = 0; i < n; i++) {
        cin.get(c);
        for (int j = 0; j < n; j++) {
            cin.get(c);
            inputMatrix[i][j] = c - '0';
        }
    }
    solve();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (resultMatrix[i][j] != '#')
                cout << '.';
            else
                cout << '#';
        }
        cout << endl;
    }
    return 0;
}
