#include <iostream>

using namespace std;

long long n;

int main() {
    cin >> n;
    long long k = n / 2 + (n % 2 -1)*(1 + (n / 2) % 2);
    cout << k << '/' << n-k;
}
