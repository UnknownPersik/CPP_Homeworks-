#include <iostream>
#include <fstream>
#include <list>
using namespace std;

int main()
{
    list<int> data = {};
    long int n, massa;
    long int counter = 0;
    int temp = 0;
    ifstream inputFile("INPUT.txt");
    if (!inputFile) {
        cout << "Create file";
        return -1;
    }
    inputFile >> n;
    inputFile >> massa;
    for (int i = 0; i < n; i++)
    {
        inputFile >> temp;
        data.push_back(temp);
    }
    data.sort();
    while (data.size() > 1){
        if (data.front() + data.back() > massa) {
            counter++;
            data.pop_back();
        }
        else {
            counter++;
            data.pop_back();
            data.pop_front();
        }
    }
    if (data.size() == 1) {
        counter++;
    }
    ofstream output("OUTPUT.txt");
    output << counter;
}
