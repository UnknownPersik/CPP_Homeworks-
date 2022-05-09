#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool prime(long n) {
    for (long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main (){
    int k;
    cin >> k;
    vector <long> massiv;
    vector <long> primeNumbers;
    primeNumbers.push_back(0);
    for (long i = 2; i < 33348; i++) // Потому что 33347 - 500-ое простое число
        if (prime(i))
            primeNumbers.push_back(i);
    for (long j = 1; j < primeNumbers.size(); j++)
        if (prime(j))
            massiv.push_back(primeNumbers[j]);
    cout << massiv[k];
}
