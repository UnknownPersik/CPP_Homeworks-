#include <iostream>
#include <vector>

using namespace std;

int n, a, b, x, y;

int main()
{
    cin >> n >> a >> b;
    vector <int> v(n+2);
    vector <int> v1;
    vector <int> v2;
    v[0] = 1; 
    v[1] = 1;
    for (int i = 2; i < n+1; i++)
        cin >> v[i];
    x = a;
    y = b;
    v1.push_back(x);
    v2.push_back(y);
    while (x != 1) {
        x = v[x];
        v1.push_back(x);
    }
    while (y != 1) {
        y = v[y];
        v2.push_back(y);
    }
    x = a;
    y = b;
    while (x != y) {
        if (v2.size() > v1.size())
        {
            v2.erase(v2.begin());
        }
        else
            v1.erase(v1.begin());
        x = v1[0];
        y = v2[0];
    }
    cout << x;
    return 0;
}
