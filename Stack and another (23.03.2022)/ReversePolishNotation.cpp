#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

ifstream inputString("INPUT.txt");
ofstream outputString("OUTPUT.txt");
string temp = "";
string postfix = "";
string infix;
stack <char> stock;
stack <float> newStack;

int priority(char symbol)
{
    switch (symbol) {
    case '+': return 0;
    case '-': return 0;
    case '/': return 1;
    case '*': return 1;
    case '^': return 2;
    default: return -1;
    }
}


int main()
{
    if (!inputString) {
        cout << "Create file";
        return -1;
    }
    inputString >> infix;
    int count = infix.length();
    for (int i = 0; i < count; i++) {
        if (infix[i] >= '0' and infix[i] <= '9') {
            postfix += " ";
            while ((infix[i] >= '0' and infix[i] <= '9') || (infix[i] == '.') || (infix[i] == ',')) {
                postfix += infix[i];
                i++;
            }
            i--;
            postfix += " ";
        }
        else if (infix[i] == '(') {
            stock.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (stock.top() != '(') {
                if (stock.size() == 0) {
                    cout << "Closing bracket error";
                    return -2;
                }
                postfix += stock.top();
                stock.pop();
            }
            if (stock.top() == '(') {
                stock.pop();
            }
        }
        else if (stock.empty() || priority(stock.top()) < priority(infix[i])) {
            stock.push(infix[i]);
        }
        else if (priority(infix[i]) <= priority(stock.top())) {
            postfix += stock.top();
            stock.pop();
            stock.push(infix[i]);
        }
    }
    while (stock.size() > 0) {
        if (stock.top() == '(') {
            cout << "Opening bracket error";
            return -1;
        }
        postfix += stock.top();
        stock.pop();
    }
    for (int i = 0; i < postfix.length(); i++) {
        if (postfix[i] == ' ') {
            i++;
            temp = "";
            while (postfix[i] != ' ') {
                temp += postfix[i];
                i++;
            }
            float number = stoi(temp);
            newStack.push(number);
        }
        else {
            float secondNumber = newStack.top();
            newStack.pop();
            float firstNumber = newStack.top();
            newStack.pop();
            if (postfix[i] == '+')
                newStack.push(firstNumber + secondNumber);
            else if (postfix[i] == '-')
                newStack.push(firstNumber - secondNumber);
            else if (postfix[i] == '*')
                newStack.push(firstNumber * secondNumber);
            else if (postfix[i] == '/')
                newStack.push(firstNumber / secondNumber);
            else if (postfix[i] == '^')
                newStack.push(pow(firstNumber, secondNumber));
        }
    }
    cout << newStack.top();
    outputString << newStack.top();
    return 0;
}
