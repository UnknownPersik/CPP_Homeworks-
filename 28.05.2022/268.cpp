#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    long long answer = n;
    for (int i = 0; i < n - 1; i++){
        int m = 0;
        int p = k;
        while (i - m >= 0 && i + m + 1 < n && (p || s[i - m] == s[i + m + 1])){
            answer += 1;
            if (s[i - m] != s[i + m + 1])
                p -= 1;
            m++;
        }
    }
    for (int i = 0; i < n - 1; i++){
        int m = 1;
        int p = k;
        while (i - m >= 0 && i + m < n && (p || s[i - m] == s[i + m])){
            answer += 1;
            if (s[i - m] != s[i + m])
                p -= 1;
            m++;
        }
    }
    cout << answer;
}

int main()
{
    int t = 1;
    while (t){
        solve();
        t--;
    }
    return 0;
}
