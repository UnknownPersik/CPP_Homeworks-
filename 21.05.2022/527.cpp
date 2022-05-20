#include <iostream>
#include <algorithm>

using namespace std;

bool algo(long long a, long long b, long long c, long long d){
    if (a == c && b == d)
        return true;
    while (b != 0){
        if (b > a){
            swap(a, b);
            if (a == c && b == d)
                return true;
        }
        if (b > 0){
            long long nSub = a / b;
            long long oldA = a;
            a -= nSub * b;
            long long newA = a;
            if (b == d && newA <= c && c <= oldA && (oldA - c) % b == 0)
                return true;
        }
    }
    return false;
}



int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++){
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if (algo(a, b, c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
