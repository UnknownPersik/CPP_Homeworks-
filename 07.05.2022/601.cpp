#include <iostream>
#include <vector>

using namespace std;

int nV, nE;

int main(){
    cin >> nV >> nE;
    const int nColors = 100;
    vector<vector<int>> dist(1 + nV, vector<int>(1 + nColors, 0));
    for (int i = 0; i < nE; i++){
        int v1, v2, color;
        cin >> v1 >> v2 >> color;
        dist[v1][color] = v2;
        dist[v2][color] = v1;
    }
    int nSteps;
    cin >> nSteps;
    int cur = 1;
    for (int i = 0; i < nSteps; i++){
        int color;
        cin >> color;
        cur = dist[cur][color];
    }
    if (cur == 0)
        cout << "INCORRECT";
    else
        cout << cur;
    return 0;
}
