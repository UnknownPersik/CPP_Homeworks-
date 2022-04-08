#include <iostream>

using namespace std;

const int N = 30;

class upgradedStack {
private:
    int size;
    int stackCounter;
    int statusCounter;
    int* array;
    int* arrayStatus = new int[N];
    int** arrayVersion = new int*[N];
public:
    upgradedStack(int inputSize) {
        stackCounter = 0;
        statusCounter = 0;
        size = inputSize;
        array = new int[size];
        for (int i = 0; i < N; i++) {
            arrayVersion[i] = new int[size];
        }
    }
    ~upgradedStack() {
        delete[] array;
        delete[] arrayStatus;
        for (int i = 0; i < N;i++) {
            delete[] arrayVersion[i];
        }
        delete[] arrayVersion;
    }

    void Push(int item) {
        if (stackCounter < size) {
            array[stackCounter++] = item;
            for (int i = 0; i < size; i++)
                arrayVersion[statusCounter][i] = array[i];
            arrayStatus[statusCounter] = stackCounter;
            statusCounter++;
        }
    }

    void Pop() {
        stackCounter--;
        for (int i = 0; i < size; i++)
            arrayVersion[statusCounter][i] = array[i];
        arrayStatus[statusCounter] = stackCounter;
        statusCounter++;
    }

    void RollBack(int n) {
        for (int i = 0; i < size; i++) {
            array[i] = arrayVersion[n][i];
        }
        stackCounter = arrayStatus[n];
    }

    int Top() {
        return array[stackCounter - 1];
    }

    void Forget() {
        statusCounter = 0;
    }
};

int main()
{
    upgradedStack stock(50);
    for (int i = 0; i < N; i++)
        stock.Push(i + 1);
    stock.RollBack(2);
    cout << stock.Top() << endl;
    stock.Forget();
    stock.RollBack(1);
    cout << stock.Top() << endl;
}
