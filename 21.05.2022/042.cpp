#include <iostream>
#include <cmath>
 
using namespace std;
 
int n;
 
int main()
{
    cin >> n;
    long long result = pow(3, n / 3);
    if (n % 3 == 1)
        result = result * 4 / 3;
    if (n % 3 == 2)
        result = result * 2;
    cout << result;
}
