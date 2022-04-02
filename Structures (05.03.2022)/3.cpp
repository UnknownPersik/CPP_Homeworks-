#include <iostream>
#include <string>
using namespace std;

struct Student {
	int age;
	string name;
	string drink;
};

bool isPrime(int number) {
	for (int j = 2; j <= sqrt(number); j++)
		if (number % j == 0)
			return false;
	return true;
}

int main(){
	Student massiv[3];
	massiv[0] = { 20, "Anna", "Tea" };
	massiv[1] = { 19, "Leon", "Coffee" };
	massiv[2] = { 27, "John", "Cola" };

	cout << "Here is information about students whose age is a prime number: " << endl;
	for (int i = 0; i < 3;i++) {
		if (isPrime(massiv[i].age))
			cout <<"Student name: " << massiv[i].name << endl <<"His(her) favourite drink: "<< massiv[i].drink << endl;
		cout << endl;
	}	
}
