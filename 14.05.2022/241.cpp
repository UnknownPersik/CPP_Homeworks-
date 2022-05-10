#include <iostream>

using namespace std;

int k;

int main(){
    cin >> k;
    cout << 2 + k % 5 + 7 * (k / 5);
    return 0;
}
