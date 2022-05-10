#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 5;
    int k = 0;
    while(i <= n)
    {
        k += n / i;
        i *= 5;
    }
    i = 1;
    int answer = 1;
    while(i <= n)
    {
        int l = i;
        while ((l % 2 == 0) & (k > 0))
        {
            l /= 2;
            k--;
        }
        while (l % 5 == 0)
        {
            l /= 5;
        }
        answer *= l;
        answer = answer % 10;
        i++;
    }
    cout << answer;
} 
