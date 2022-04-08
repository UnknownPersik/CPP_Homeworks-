#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	int n, m, need1, need2, need3;
	int index = 0;
	cin >> n;
	cin >> m;
	vector <int> vect(n);
	for (int i = 0; i < n; ++i) {
		cin >> vect[i];
	}
	for (int i = 0; i < m; ++i) {
		need1 = vect[index];
		need2 = vect[(index + 1 + n) % n];
		need3 = vect[(index + 2 + n) % n];
		vect[index] = 0;
		vect[(index + 1 + n) % n] = 0;
		vect[(index + 2 + n) % n] = 0;
		int ind = 0;
		if (need1 == 1 || (need1 == 2 && (need2 == 1 || need3 == 1)) || ((need1 == 3 && (need2 + need3 == 3)))) {
			for (int j = 0; j < n; ++j) {
				if (vect[j] > vect[ind]) {
					ind = j;
				}
			}
		}
		else {
			for (int j = 0; j < n; ++j) {
				if (vect[j] < need1 && vect[j] > vect[ind]) {
					ind = j;
				}
			}
		}
		while (index != ind) {
			vect[(index + 2 + n) % n] = vect[(index - 1 + n) % n];
			index = (index - 1 + n) % n;
		}
		vect[ind] = need1;
		vect[(ind + 1 + n) % n] = need2;
		vect[(ind + 2 + n) % n] = need3;
		index = (index + 3 + n) % n;
	}
	for (int i = 0; i < n; ++i) {
		cout << vect[i] << " ";
	}
	return 0;
}
