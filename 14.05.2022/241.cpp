#include <iostream>

using namespace std;

int k;

int main(){
    cin >> k;
    int result =  2 + k % 5 + 7 * (k / 5);
    if (k > 36)
        result++;
    if (k > 44)
        result++;
    if (result == 56 || result == 63 || result == 70 || result == 71)
        result += 2;
    cout << result;
    return 0;
}
