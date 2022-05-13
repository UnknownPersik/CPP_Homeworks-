#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> st;

    int n, m;
    cin >> n >> m;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        st.insert(t);
    }

    for (int i = 0; i < m; i++) {
        int tmp = *st.begin() + 1;
        st.erase(st.begin());
        st.insert(tmp);
    }

    cout << *st.begin();
    return 0;
}
