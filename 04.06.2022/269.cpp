#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string a, b;
    cin >> a;
    cin >> b;
    int minLen = a.length() + b.length();
    for (int bPos = 0-(int)b.length(); bPos <= (int)a.length(); bPos++){
        int first = min(bPos, 0);
        int last = max(bPos + (int)b.length() - 1, (int)a.length() - 1);
        bool good = true;
        for (int i = first; i <= last; i++){
            int aVal, bVal;
            if (0 <= i && i < (int)a.length()){
                aVal = a[i] - '0';
            }
            else{
                aVal = 1;
            }
            if (bPos <= i && i < bPos + (int)b.length()){
                bVal = b[i - bPos] - '0';
            }
            else{
                bVal = 1;
            }
            if (aVal + bVal > 3){
                good = false;
                break;
            }
        }
        if (good){
            int len = last - first + 1;
            if (len < minLen)
                minLen = len;
        }
    }
    cout << minLen;
    return 0;
}
