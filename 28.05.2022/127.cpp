#include <fstream>
#include <queue>
#include <vector>

using namespace std;

int n, i, j, k, f, s;
queue <int> q;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    out.clear();
    in >> n;
    vector<vector<int>> a(n, vector <int>(n, 0));
    vector<int> d(n, 1000000);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            in >> a[i][j];
    in >> s >> f;
    s--;
    f--;
    d[s] = 0;
    q.push(s);
    while (!q.empty()){
        i = q.front();
        q.pop();
        for (j = 0; j < n; j++){
            if (a[i][j] && d[j] > d[i] + 1){
                d[j] = d[i] + 1;
                q.push(j);
            }
        }
    }
    if (d[f] < 1000000)
        out << d[f];
    else
        out << -1;
    return 0;
}
