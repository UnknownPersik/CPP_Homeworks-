#include <iostream>
#include <list>
#include <ctime>
 
using namespace std;
 
int main()
{
    srand(time(0));
    float totalCount = 0;
    float mediumCount = 0;
    int elementsCount = 9999;
    list<float> massiv = {};
    for (int i = 0; i < elementsCount; i++)
    {
        massiv.push_back((float)(rand() % 201 - 100)); // Создаем лист рандомных чисел -100 до 100, размерностью 10000
    }
    for (float m : massiv)
    {
        totalCount += m;
    }
    mediumCount = (totalCount / elementsCount);
    cout << mediumCount << endl;
}
