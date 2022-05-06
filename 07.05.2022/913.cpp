#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int main() {
    cin >> N >> M;
    vector<pair<int, int>> road(N);
    int Di, Li, Hi;
    int roadLength = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> Di >> Li >> Hi;
        road[i] = pair<int, int>(min(Li, M), Hi);
        roadLength += Di;
    }
    sort(road.begin(), road.end());
    int speed = road[0].first;
    int amountH = 0;
    double minTime = INT32_MAX;
    for(auto segment : road)
    {
        if (1.0 * roadLength / segment.first + amountH <= minTime)
        {
            minTime = 1.0 * roadLength / segment.first + amountH;
            speed = segment.first;
        }
        amountH += segment.second;
    }
    cout << speed << endl;
}
