#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
ofstream output("OUTPUT.txt");

int main()
{
    int length, maximumLength;
    long long right = -1;
    long long result = 0;
    ifstream inputFile("INPUT.txt");
    if (!inputFile) {
        cout << "Create file";
        return -1;
    }
    inputFile >> length >> maximumLength;
    string s;
    inputFile >> s;
    vector<int> count(128, 0);
    for (int left = 0; left < length; left++)
    {
        while (right + 1 < length && count[(int)s[right + 1]] < maximumLength) {
            right++;
            count[(int)s[right]]++;
        }
        result += right + 1 - left;
        count[(int)s[left]]--;
    }   
    output << result;
}
