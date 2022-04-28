#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream input("INPUT.txt");
ofstream output("OUTPUT.txt");
string inputText, substringText;

vector<int> prefix_function(const string& text) {
    vector<int> prefixs(text.length(), 0);
    for (int i = 1; i < text.length(); i++) {
        int j = prefixs[i - 1];
        while (j > 0 && text[i] != text[j]) {
            j = prefixs[j - 1];
        }
        if (text[i] == text[j]) {
            prefixs[i] = j + 1;
        }
        else {
            prefixs[i] = j;
        }
    }
    return prefixs;
}

int main() {
    if (!input) {
        cout << "Create file";
        return -1;
    }
    input >> inputText >> substringText;
    vector<int> prefixFunc = prefix_function(substringText + '#' + inputText);
    int substringLength = substringText.length();
    int inputTextLength = inputText.length();
    for (int i = 0; i < inputTextLength; i++) {
        if (prefixFunc[substringLength + 1 + i] == substringLength) {
            output << i - substringLength + 1 << " ";
        }
    }
}
