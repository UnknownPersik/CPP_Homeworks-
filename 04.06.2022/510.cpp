#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> counter(n + 1), sum(n + 1);
    counter[0] = 1;
    sum[0] = 1;
    if (n % 2 == 1){
        cout << 0;
        return 0;
    }
    for (int i = 2; i <= n; i++){
        counter[i] = counter[i - 2] + 2 * sum[i - 2];
        sum[i] = sum[i - 2] + counter[i];
    }
    cout << counter[n];
    return 0;
}
