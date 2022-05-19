#include <iostream>
#include <vector>

using namespace std;

int b;

int main()
{
    cin >> b;
    if (b == 1 || b == 2 || b == 3 || b == 6){
        cout << -1;
        return 0;
    }
    if(b == 4){
        cout << 2 << endl << 1 << endl << 0 << endl << 1;
        return 0;
    }
    if(b == 5){
        cout << 1 << endl << 2 << endl << 0 << endl << 0 << endl << 2;
        return 0;
    }
    vector<int> massiv(b + 1);
    massiv[1] = 2;
    massiv[2] = 1;
    massiv[b - 4] = 1;
    massiv[b] = b - 4;
    for(int i = 1; i < massiv.size(); ++i)
        cout << massiv[i] << endl;
    return 0;
}
