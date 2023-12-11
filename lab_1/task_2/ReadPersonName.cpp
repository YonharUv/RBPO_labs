#include <iostream>
#include "Functions.h"


using namespace std;

string ReadPersonName() {
	string name;
	cout << "Введите имя: ";
	cin >> name;
	return name;
}