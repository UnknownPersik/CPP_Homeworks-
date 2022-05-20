#include <iostream>
#include <string>

using namespace std;

string N;
int K;

int main(){
       cin >> N >> K;
       int c = 0;
       long long umen = 0;
       bool flag = 0;
       while (c < N.length()){
            while (umen < K && c < N.length()){
                    umen = umen * 10 + N[c] - '0';
                    if (umen < K && flag) cout << 0;
                    c++;
            }
            if (umen < K && !flag){
                cout << 0;
                return 0; 
            }
            flag = 1;
            if (umen >= K) 
                cout << umen / K;
            umen %= K;
       }
       return 0;
}
