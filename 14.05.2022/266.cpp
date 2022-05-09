#include <iostream>
#include <vector>

using namespace std;

int n, hoursFirWork, minFirWork, hoursSecWork, minSecWork;
vector<int> times(1440);

int main()
{
    int answ = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> hoursFirWork >> minFirWork >> hoursSecWork >> minSecWork;
        int timeFirWork = hoursFirWork * 60 + minFirWork;
        int timeSecWork = hoursSecWork * 60 + minSecWork;
        if (timeFirWork >= timeSecWork)
        {
            for (int j = timeFirWork; j < 1440; ++j)
                times[j]++;
            for (int j = 0; j < timeSecWork; ++j)
                times[j]++;
        }
        else
            for (int j = timeFirWork; j < timeSecWork; ++j)
                times[j]++;
    }
    for (auto c : times)
        if (c == n)
            ++answ;
    cout << answ;
    return 0;
}
