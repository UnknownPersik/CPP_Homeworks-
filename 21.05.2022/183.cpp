#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


int main() {
    map<int, long long> mp;
    mp.emplace(2, 1);
    int k, p;
    cin >> k >> p;
    if (k == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 3; i <= k; ++i) {
        if (i % 2 == 1) {
            mp.emplace(i, mp[i - 1] % p);
        }
        else {
            mp.emplace(i, (mp[i - 1] + mp[i / 2]) % p);
            mp.erase(i / 2);
        }
    }
   	cout << mp[k];
    return 0;
}
