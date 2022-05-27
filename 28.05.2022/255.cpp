#include <iostream>
#include <cmath>

using namespace std;

long long d, n;
bool isFound;

int main(){
    cin >> n;
    isFound = false;
    for (int q = 2; q <= trunc(sqrt(n)) + 1; q++){
        if (n % q == 0){
            d = n / q;
            cout << d << ' ' << n - d;
            isFound = true;
            break;
        }
    }
    if (!isFound)
        cout << 1 << ' ' << n - 1;
    return 0;
}
