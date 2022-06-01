#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define ut unsigned int

using namespace std;

int main()
{
    ut n, h, m, s;
    vector<ut> v;
    cin >> n;
    for (ut i = 0; i < n; i++){
        scanf("%u:%u:%u", &h, &m, &s);
        v.push_back((s + 60 * (m + 60 * h)) % (12 * 60 * 60));
    }
    sort(v.begin(), v.end());
    ut sum = 12 * 60 * 60 * n - accumulate(v.begin(), v.end(), 0);
    ut min = numeric_limits<ut>::max(), mint = 0, prev = 0;
    for (ut i = 0; i < n; prev = v[i++])
        if ((sum += n * (v[i] - prev) - 12 * 60 * 60) < min)
            mint = v[i], min = sum;
    if (mint < 3600)
        mint += 3600*12;
    if (mint / 60 % 60 < 10 && mint % 60 < 10){
        cout << mint / 3600 << ":0" << mint / 60 % 60 << ":0" << mint % 60;
        return 0;
    }
    if (mint / 60 % 60 < 10 && mint % 60 > 9){
        cout << mint / 3600 << ":0" << mint / 60 % 60 << ':' << mint % 60;
        return 0;
    }
    if (mint / 60 % 60 > 9 && mint % 60 < 10){
        cout << mint / 3600 << ":" << mint / 60 % 60 << ":0" << mint % 60;
        return 0;
    }
    cout << mint / 3600 << ":" << mint / 60 % 60 << ":" << mint % 60;
    return 0;
}
