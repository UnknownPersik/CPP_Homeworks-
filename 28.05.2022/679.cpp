#include <iostream>
#include <cmath>

using namespace std;

int n;

int main(){
    int counterTwo = 0, counterThree = 0;
    cin >> n;
    while (n % 3 > 0 && n > 0){
        n -= 2;
        counterTwo++;
    }
    counterThree += n / 3;
    if (counterTwo > 0)
        cout << 2 << ' ' << counterTwo;
    if (counterTwo > 0 && counterThree > 0)
        cout << ' ';
    if (counterThree > 0)
        cout << 3 << ' ' << counterThree;
    return 0;
}
