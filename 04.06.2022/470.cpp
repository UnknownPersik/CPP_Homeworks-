#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int height, weight, n;
    cin >> height >> weight >> n;
    vector<vector<int>> massiv(height + 1, vector<int>(weight + 1, 0));
    for (int i = 1; i <= height; i++){
        for (int j = 1; j <= weight; j++){
            cin >> massiv[i][j];
            massiv[i][j] += massiv[i][j - 1] + massiv[i - 1][j] - massiv[i - 1][j - 1];
        }
    }
    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << massiv[x2][y2] - massiv[x2][y1 - 1] - massiv[x1 - 1][y2] + massiv[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}
