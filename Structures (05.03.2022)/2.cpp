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
	int max = 0;
	massiv[0] = { 20, "Anna", "Tea" };
	massiv[1] = { 19, "Leon", "Coffee" };
	massiv[2] = { 27, "John", "Cola" };

  for (int i = 0; i < 3; i++)	{
		if (massiv[i].age >= max)
			max = massiv[i].age;
	}
	cout << "The biggest age on group: " << max << endl;
}
