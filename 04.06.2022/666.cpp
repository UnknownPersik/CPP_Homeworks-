#include <iostream>
#include <cmath>

using namespace std;

void solve(){
    int n;
    cin >> n;
    for (int i = 26; i > 0; i--){
        if (n == 1){
            cout << char('a' + i - 1);
            return;
        }
        else{
            if (n <= pow(2, i - 1)){
                n--;
            }
            else{
                n -= pow(2, i - 1);
            }
        }
    }
}

int main()
{
    solve();
    return 0;
}
