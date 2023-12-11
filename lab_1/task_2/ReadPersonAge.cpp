#include <iostream>
#include "Functions.h"

using namespace std;

unsigned short int ReadPersonAge() {
	unsigned short int age;
	cout << "Введите возраст: ";
	cin >> age;
	return age;
}