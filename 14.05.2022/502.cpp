#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector < vector<int>> mas(1 + n, vector<int>(1 + n));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mas[i][j];
        }
    }

    int min_int = numeric_limits<int>::min();
    vector<vector<int>>max_mas(n + 1, vector<int>(n + 1, min_int));
    max_mas[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            max_mas[i][j] = max_mas[i - 1][j];
            for (int k = 1; k <= j; ++k)
                max_mas[i][j] = std::max(max_mas[i][j], mas[k][i] + max_mas[i - 1][j - k]);
        }
    }

    cout << max_mas[n][n];
    return 0;
}
