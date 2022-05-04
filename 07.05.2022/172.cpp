#include <iostream>
#include <string>
#include <vector>

using namespace std;

string firstNumber;
long long secondNumber;
vector <int> massiv;
const int base = 1000000000;

int main()
{
    cin >> firstNumber >> secondNumber;
    for (int i = firstNumber.length(); i > 0; i-=9){
        if (i < 9)
            massiv.push_back(atoi(firstNumber.substr(0, i).c_str()));
        else
            massiv.push_back(atoi(firstNumber.substr(i - 9, 9).c_str()));
    }
    int leftover = 0;
    for (int j = massiv.size() - 1; j >= 0; j--){
        long long cur = massiv[j] + (long long)leftover * base;
        massiv[j] = (int)(cur / secondNumber);
        leftover = (int)(cur % secondNumber);
    }
    cout << leftover;
    return 0;
}
