#include <iostream>
using namespace std;

class Queue1
{
private:
    int size; // Размер очереди
    int* massiv; 
    int count; // Количество элементов в очереди

public:
    Queue1(int razmer) // Конструктор по умолчанию
    {
        size = razmer;
        massiv = new int[size];
        count = 0;
    }
    ~Queue1() // Деструктор
    {
        if (count > 0)
            delete[] massiv;
    }

    void Push(int item) // Добавляем элемент в очередь
    {
        if (sizeof(massiv) == count)
            massiv[count++] = item;
    }

    int Pop() // Вытягиваем первый элемент из очереди
    {
        if (count == 0)
            return 0;
        int item;
        item = massiv[0];
        return item;
    }

    int GetItem() // Берем первый элемент из очереди не вытягивая его
    {
        if (count > 0)
            return massiv[0];
        else
            return 0;
    }

    void Clear() // Очистка очереди
    {
        if (count > 0)
        {
            delete[] massiv;
            count = 0;
        }
    }

    bool IsEmpty() // Проверка существования элементов в очереди
    {
        return count == 0;
    }

    int GetSize() // Возвращает количество элементов в очереди
    {
        return count;
    }
};

int main() {
    return 0;
}
