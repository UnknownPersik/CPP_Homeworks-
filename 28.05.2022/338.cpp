#include <iostream>

const int N = 105;

using namespace std;

int n, m, massiv[N][N], counts = 1;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y) {
    return x > 0 && y > 0 && x <= n && y <= m;
}

void dfs(int row, int column) {
    massiv[row][column] = counts;
    for (int i = 0; i < 4; i++) {
        int x = row + dx[i];
        int y = column + dy[i];
        if (valid(x, y))
            if (!massiv[x][y])
                dfs(x, y);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> massiv[i][j];
    for (int z = 1; z <= n; z++)
        for (int k = 1; k <= m; k++)
            if (!massiv[z][k]) {
                dfs(z, k);
                counts++;
            }
    cout << counts - 1;
    return 0;
}
