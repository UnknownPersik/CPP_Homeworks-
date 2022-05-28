#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int sum = 0;
    cin >> n;
    vector<int> massiv(n);
    for (int i = 0; i < n; i++){
        cin >> massiv[i];
        sum += massiv[i];
    }
    sort(massiv.begin(), massiv.end());
    int massivMax = massiv[n - 1];
    int massivMin = min(sum / 2, sum - massivMax);
    cout << massivMin;
    return 0;
}
