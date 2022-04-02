#include <iostream>
#include <string>
using namespace std;

struct Student {
	int age;
	string name;
	string drink;
};

int main(){
	Student massiv[3];
	cout << "Input data about students" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Input age: ";
		cin >> massiv[i].age;
		cout << "Input name: ";
		cin >> massiv[i].name;
		cout << "Input drink: ";
		cin >> massiv[i].drink;
		cout << endl;
	}
  //Or inpute data about students like this
	//massiv[0] = { 20, "Anna", "Tea" };
	//massiv[1] = { 19, "Leon", "Coffee" };
	//massiv[2] = { 27, "John", "Cola" };

cout << "Information about students: " << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << " " << "student age: " << massiv[i].age << " " << "drink: " << massiv[i].drink << " " << "name: " << massiv[i].name << endl;
	}
	cout << endl;
}
