#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");
int n, x, y, nod, temp1, temp2, time;

int NOD(int a, int b)
{
    int temp;
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    temp = b;
    while (temp % a != 0)
        temp += b;
    return temp;
}

int main() {
    if (!input) {
        cout << "Create file";
        return -1;
    }
    input >> n >> x >> y;
    if (x > y) {
        temp1 = x;
        x = y;
        y = temp1;
    }
    time = x;
    nod = NOD(x, y);
    temp1 = nod / x + nod / y;
    time += ((n - 1) / temp1) * nod;
    n = (n - 1) % temp1;
    temp1 = 0;
    temp2 = 0;
    while (n > 0) {
        temp1++;
        temp2++;
        time++;
        if (temp1 >= x) {
            n--;
            temp1 = temp1 % x;
        }
        if (temp2 >= y) {
            n--;
            temp2 = temp2 % y;
        }
    }
    output << time;
    return 0;
}
