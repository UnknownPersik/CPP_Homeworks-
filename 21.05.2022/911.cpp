#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(const vector <long long> &vec)
{
    for (auto c : vec)
        cout << c << " ";
    cout << endl;
}

int main() {
    char c;
    long long n, t = 1, r = 0;
    cin >> c >> n;
    vector <long long> L, R;
    while(n > 0)
    {
        r = n % 3;
        if (r == 2) {
            L.push_back(t);
            n += 3;
        }
        else if (r == 1)
            R.push_back(t);
        t *= 3;
        n /= 3;
    }
    if (c == 'L')
    {
        cout << "L:";
        print(L);
        cout << "R:";
        print(R);
    }
    else
    {
        cout << "L:";
        print(R);
        cout << "R:";
        print(L);
    }
    return 0;
}
