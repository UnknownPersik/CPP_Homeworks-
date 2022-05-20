#include <vector>
#include <iostream>

using namespace std;


int main() {

    int n, m, x, y, p;
    float mid_x, mid_y, a, b, c;
    bool flag = true;
    cin >> n >> m;
    vector<pair<int, int>> mas;
    pair<int, int> plug;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        plug.first = x;
        plug.second = y;
        mas.push_back(plug);
    }
    mid_x = float(n) / 2;
    mid_y = float(n) / 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == mid_x && j == mid_y)
                continue;
            a = j - mid_y;
            b = -i + mid_x;
            c = -mid_x * (j - mid_y) + -mid_y * (-i + mid_x);
            if (a * mas[0].first + b * mas[0].second + c > 0)
                p = 1;
            else if (a * mas[0].first + b * mas[0].second + c < 0)
                p = -1;
            else
                continue;
            flag = true;
            for (int f = 1; f < m; ++f) {
                if (p == 1) {
                    if (a * mas[f].first + b * mas[f].second + c <= 0) {
                        flag = false;
                        break;
                    }
                }
                else {
                    if (a * mas[f].first + b * mas[f].second + c >= 0) {
                        flag = false;
                        break;
                    }
                }

            }
            if (flag) {
                cout << "YES";
                return 0;
            }

        }
    }
    cout << "NO";
    return 0;
}
