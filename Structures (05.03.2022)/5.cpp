#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    string value;
    int victories;
};

int RPS(string value1, string value2) {
    if (value1 == "Rock") {
        if (value2 == "Scissors")
            return 1;
        if (value2 == "Paper" || value2 == "Rock")
            return 0;
    }

    if (value1 == "Scissors") {
        if (value2 == "Paper")
            return 1;
        if (value2 == "Rock" || value2 == "Scissors")
            return 0;
    }

    if (value1 == "Paper") {
        if (value2 == "Rock")
            return 1;
        if (value2 == "Scissors" || value2 == "Paper")
            return 0;
    }
}

int main() {
    Student massiv[5];
    int maximumVictories = 0;
    int winner = 0;
    
    massiv[0] = { "Anna", "Rock", 0 };
    massiv[1] = { "Leon", "Paper", 0 };
    massiv[2] = { "John", "Scissors", 0 };
    massiv[3] = { "Lena", "Rock", 0 };
    massiv[4] = { "Joe", "Scissors", 0 };

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (i == j)
                continue;
            else {
                string value1 = massiv[i].value;
                string value2 = massiv[j].value;
                massiv[i].victories += RPS(value1, value2);
                massiv[j].victories += RPS(value2, value1);
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        if (massiv[i].victories >= maximumVictories) {
            maximumVictories = massiv[i].victories;
            winner = i;
        }
    }

    cout << "Winner: " << massiv[winner].name << " " << "with " << massiv[winner].victories << " victories";
}
