#include <iostream>

using namespace std;

int n, i, j, k;

int main(){
    cin >> n;
    int matrix[n][n];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> matrix[i][j];
            if (matrix[i][j] < 0)
                matrix[i][j] = 1000000000;
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            for (int k = 0; k < n; ++k){
                if (matrix[j][k] > matrix[j][i] + matrix[i][k])
                    matrix[j][k] = matrix[j][i] + matrix[i][k];
            }
        }
    }
    int result = 0;
    for (int j = 0; j < n; ++j){
        for (int k = 0; k < n; ++k){
            if (matrix[j][k] < 1000000000 && matrix[j][k] > result)
                result = matrix[j][k];
        }
    }
    cout << result;
    return 0;
}
