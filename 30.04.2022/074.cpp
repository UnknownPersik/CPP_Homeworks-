#include <iostream>
#include <fstream>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");
long long n, m;

int main()
{
    if (!input) {
        cout << "Create file";
        return -1;
    }
    input >> n >> m;
    if (m == 1) {
        output << n;
        return 0;
    }
    int countWhoLose = 0;
    int positionBetweenRounds = m;
    while (n > 1) {
        if (positionBetweenRounds % 2 == 0) {
            output << countWhoLose + positionBetweenRounds / 2;
            return 0;
        }
        else {
            positionBetweenRounds = positionBetweenRounds / 2 + 1;
            countWhoLose = countWhoLose + n / 2;
            if (n % 2 == 0)
                n /= 2;
            else
                n = n / 2 + 1;
        }
    }
    return 0;
}
