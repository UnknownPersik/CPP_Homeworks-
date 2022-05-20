#include <vector>
#include <iostream>

using namespace std;

void act(vector<vector<int>> &vec, int x, int y, int n, int m) {
    if (vec[x][y] != 0) {
        return;
    }
    vec[x][y] = 1;
    if (x + 1 < n) {
        if (vec[x + 1][y] == 0) {
            act(vec, x + 1, y, n, m);
        }
    }
    if (y - 1 >= 0) {
        if (vec[x][y - 1] == 0) {
            act(vec, x, y - 1, n, m);
        }
    }
    if (y + 1 < m) {
        if (vec[x][y + 1] == 0) {
            act(vec, x, y + 1, n, m);
        }
    }
    if (x - 1 >= 0) {
        if (vec[x - 1][y] == 0) {
            act(vec, x - 1, y, n, m);
        }
    }
}

int main() {
    int ans = 0;
    int n, m, k, x, y;
    cin >> n >> m;
    char str;
    vector<vector<int>> mas;
    vector<int> plug;
    for (int i = 0; i < n; ++i) {
        plug.clear();
        for (int j = 0; j < m; ++j) {
            plug.push_back(0);
        }
        mas.push_back(plug);
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> x >> y;
        mas[x - 1][y - 1] = 2;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mas[i][j] == 0) {
                ans++;
                act(mas, i, j, n, m);
            }
        }
    }
    cout << ans;
    return 0;
}
