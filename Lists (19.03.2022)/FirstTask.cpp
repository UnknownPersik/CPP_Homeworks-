#include <iostream>
#include <fstream>
#include <list>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    float totalCounter1 = 0;
    float elementsFromMassiv = 0;
    float mediumCounter = 0;
    list<float> anotherMassiv = {};
    
    ofstream generateRandomNumbers("someData.txt");
    for (int i = 0; i < 9999; i++)
        generateRandomNumbers << (float)(rand() % 201 - 100) << "\n"; //Здесь идет генерация рандомных чисел от -100 до 100, с последующей записью в файл.
    generateRandomNumbers.close();
    
    ifstream openedData("someData.txt");
    if (!openedData)
    {
        cout << "Something wrong" << endl;
        return -1;
    }
    else
    {
        cout << "Enjoy check that" << endl;
    }
    while (!openedData.eof())
    {
        float temp;
        openedData >> temp;
        anotherMassiv.push_back(temp);
        totalCounter1 += temp;
    }
    openedData.close();
    anotherMassiv.sort();
    for (float i : anotherMassiv)
        cout << i << " ";
    mediumCounter = totalCounter1 / anotherMassiv.size();
    cout << endl;
    cout << mediumCounter;
}
