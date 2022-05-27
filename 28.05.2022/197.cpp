#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m = 1;
    cin >> n;
    vector<vector<long long>> massiv(n, vector<long long>(n, 0));
    int x = 0, y = 0;
    massiv[0][0] = 1;
    while (m < n * n){
        if (n == 1)
            break;
        if (x < n - 1)
            x++;
        else if (y < n - 1)
            y++;
        else
            break;
        m++;
        massiv[x][y] = m;
        while (x > 0 && y < n - 1){
            x--;
            y++;
            m++;
            massiv[x][y] = m;
        }
        if (y == n - 1)
            x++;
        else if (x == n - 1)
            break;
        else 
            y++;
        m++;
        massiv[x][y] = m;
        while (x < n - 1 && y > 0){
            x++;
            y--;
            m++;
            massiv[x][y] = m;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << massiv[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
