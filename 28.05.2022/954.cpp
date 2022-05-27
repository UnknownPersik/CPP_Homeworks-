#include <iostream>
#include <vector>

using namespace std;

int height;

int main()
{
    cin >> height;
    vector<int> counts(height + 1, 0);
    counts[0] = 1;
    for(int i = 1; i <= height; i++)
    {
        if (i >= 10)
            counts[i] += counts[i - 10];
        if (i >= 11)
            counts[i] += counts[i - 11];
        if (i >= 12)
            counts[i] += counts[i - 12];
        counts[i] %= 1000000;
    }
    cout << counts[height] * 2 % 1000000;
    return 0;
}
