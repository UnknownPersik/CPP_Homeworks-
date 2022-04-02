#include <iostream>
#include <string>

using namespace std;

struct Student
{
    int age;
    string name;
    string drink;
};

int main() {
    Student massiv[3];
    string reverseNames[3];
    
    massiv[0] = { 20, "Anna", "Tea" };
    massiv[1] = { 19, "Leon", "Coffee" };
    massiv[2] = { 27, "John", "Cola" };

    for (int i = 0; i < 3; i++) {
        int length = massiv[i].name.length();
        string s1 = "";
        for (int j = 0; j < length; j++) {
            s1 += massiv[i].name[length - j - 1];
        }
        reverseNames[i] = s1;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i - 1;j++){
            if (reverseNames[j] > reverseNames[j + 1])
                swap(reverseNames[j], reverseNames[j + 1]);
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << reverseNames[i] << endl;
    }
}
