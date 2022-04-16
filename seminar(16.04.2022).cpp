#include <algorithm>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

ifstream input("in.txt");

struct Node {
    int x, y, step;
};

const int maxn = 900;
char Map[maxn][maxn];
bool visitedCells[maxn][maxn];
int f[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
queue <Node> Q;
int n, m;

bool jud(int i, int j) {
    Node start;
    int ret = 0;
    if (Map[i - 1][j] == '#') {
        ret++;
    }
    if (Map[i][j - 1] == '#') {
        ret++;
    }
    if (Map[i + 1][j] == '#') {
        ret++;
    }
    if (Map[i][j + 1] == '#') {
        ret++;
    }
    if (ret >= 3) {
        start.x = i, start.y = j, start.step = 0;
        Q.push(start);
        return true;
    }
    return false;
}

Node BFS() {
    Node start, temp, end;
    end = Q.front();
    visitedCells[end.x][end.y] = 1;
    while (!Q.empty()) {
        start = Q.front();
        Q.pop();
        if (start.step > end.step) {
            end = start;
        }
        for (int i = 0; i < 4; i++) {
            temp.x = start.x + f[i][0];
            temp.y = start.y + f[i][1];
            if (temp.x <= 0 || temp.x > m || temp.y <= 0 || temp.y > n || Map[temp.x][temp.y] == '#' || visitedCells[temp.x][temp.y]) {
                continue;
            }
            visitedCells[temp.x][temp.y] = 1;
            temp.step = start.step + 1;
            Q.push(temp);
        }
    }
    return end;
}

int main() {
    input >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            input >> Map[i][j];
        }
    }
    int flag = 0;
    for (int i = 1; i <= m; i++) {
        if (flag)
            break;
        for (int j = 1; j <= n; j++) {
            if (Map[i][j] == '.' && flag == 0) {
                flag = jud(i, j);
            }
            if (flag)
                break;
        }
    }
    Node start = BFS();
    memset(visitedCells, 0, sizeof(visitedCells));
    start.step = 0;
    Q.push(start);
    Node end = BFS(); // Вторым BFS 
    cout << end.step;
    return 0;
}
