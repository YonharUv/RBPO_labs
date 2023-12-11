#pragma once
#include <iostream>

using namespace std;

string salary_str = "";

void WritePersonData(string& name, string& height, string& weight, const unsigned short* age) {
	cout << "Имя: " << name << endl;
	cout << "Рост: " << height << endl;
	cout << "Вес: " << weight << endl;
	cout << "Возраст: " << (*age) << endl;
	cout << "Зарплата: " << salary_str << endl;
}