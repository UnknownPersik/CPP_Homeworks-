#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long

vector<ll> factorize(ll x){
    vector<ll> factor;
    for (ll i = 2; i <= sqrt(x); i++) {
        while (x % i == 0) {
            factor.push_back(i);
            x /= i;
        }
    }
    if (x != 1) {
        factor.push_back(x);
    }
    return factor;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> massiv = factorize(n);
    cout << "Prime dividers for input number is:" << endl;
    for (int i = 0; i < massiv.size(); i++){
        cout << massiv[i] << " ";   
    }
    return 0;
} 
