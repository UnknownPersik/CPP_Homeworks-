#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int gcd(int a, int b){
    if (b==0)
        return a;
    return gcd(b, a%b);
}

struct drob
{
    int ch,zn;
    drob(){}
    drob(int Ch, int Zn)
    {
        ch = Ch;
        zn = Zn;
    }
    void output()
    {
        cout << ch << "/" << zn << endl;
    }
};

bool operator < (const drob &a, const drob &b)
{
    return (double)a.ch / a.zn  < (double)b.ch / b.zn;
}

vector<drob> mas;

void solve()
{
    for (int zn = 2; zn <= n; zn++)
        for (int ch = 1; ch < zn; ch++)
            if (gcd(ch, zn) == 1)
                mas.push_back(drob(ch, zn));
    sort(mas.begin(), mas.end());
}

int main()
{
    cin >> n;
    solve();
    for (int i = 0; i < mas.size(); i++)
        mas[i].output();
    return 0;
}
