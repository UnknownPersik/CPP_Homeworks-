#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool comp(int firstElement, int secondElement){
    if (firstElement / 10 > 0 || secondElement / 10 > 0){
        cout << -1 << " " << -1;
        exit(0);
    }
    return firstElement > secondElement;
}

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int m;
    cin >> m;
    int copiya = m;
    vector<int> findMaximum;
    int findMinimum[10];
    if (isPrime(m) && m / 10 > 0){
        cout << -1 << " " << -1;
        return 0;
    }
    long minNumber, maxNumber;
    for (int i = 2; i <= sqrt(m); i++) {
        while (m % i == 0) {
            findMaximum.push_back(i);
            m /= i;
        }
    }
    if (m != 1) {
        findMaximum.push_back(m);
    }
    for (int i = 9; i > 1; --i) {
        findMinimum[i] = 0;
        while (copiya % i == 0) {
            copiya /= i;
            findMinimum[i]++;
        }
    }
    if (copiya == 1) {
        for (int i = 2; i <= 9; ++i) {
            while (findMinimum[i]) {
                findMinimum[i]--;
                cout << i;
            }
        }
    }
    cout << " ";
    sort(findMaximum.begin(), findMaximum.end(), comp);
    for (int i = 0; i < findMaximum.size(); i++)
        cout << findMaximum[i];
    return 0;
}
