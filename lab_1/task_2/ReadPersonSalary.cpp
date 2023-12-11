#include <iostream>
#include "Functions.h"

using namespace std;

void ReadPersonSalary(double* salary) {
	cout << "Введите заработную плату: ";
	cin >> (*salary);
}