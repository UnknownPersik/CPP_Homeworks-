#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int n;
double dol_max, eur_max, rub_max;

int main() {
    cin >> n;
    dol_max = 0;
    eur_max = 0;
    rub_max = 100;
    double dol_rate, eur_rate;
    for (int i = 0; i < n; i++) {
        cin >> dol_rate >> eur_rate;
        rub_max = max(rub_max, max(eur_max * eur_rate,  dol_max * dol_rate));
        eur_max = max(eur_max, max(rub_max / eur_rate, dol_max * dol_rate / eur_rate));
        dol_max = max(dol_max, max(rub_max / dol_rate, eur_max * eur_rate / dol_rate));
    }
    cout << fixed << setprecision(2) << rub_max;
}
