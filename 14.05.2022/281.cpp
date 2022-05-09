#include <iostream>
#include <fstream>

using namespace std;

long long fact(int x)
{
    if (x == 0)
        return 1;
    return x * fact(x - 1);
}

long long combin(int n, int k)
{
    return fact(n) / (fact(k) * fact(n - k));
}

int n, m;

int main()
{
    cin >> n >> m;
    long long answer = 0;
    for (int k = m; k <= n; ++k){
        answer += combin(n, k);
    }
    cout << answer;
    return 0;
}
