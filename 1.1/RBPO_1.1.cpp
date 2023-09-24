#include <iostream>
#include <string>

using namespace std;

unsigned short height;
string salary_str = "";

unsigned short ReadPersonAge() {
	unsigned short age;
	cout << "Введите возраст: ";
	cin >> age;
	return age;
}
string ReadPersonName() {
	string name;
	cout << "Введите имя: ";
	cin >> name;
	return name;
}
void ReadPersonHeight() {
	cout << "Введите рост: ";
	cin >> height;
}
void ReadPersonWeight(unsigned short& weight) {
	cout << "Введите вес: ";
	cin >> weight;
}
void ReadPersonSalary(double* salary) {
	cout << "Введите заработную плату: ";
	cin >> (*salary);
}
void ReadPersonData(string& name, unsigned short& age, double& salary) {
	age = ReadPersonAge();
	name = ReadPersonName();
	ReadPersonSalary(&salary);
}
void ReadPersonData(string& name, unsigned short& age, unsigned short& height, unsigned short& weight) {
	age = ReadPersonAge();
	name = ReadPersonName();
	ReadPersonHeight();
	ReadPersonWeight(weight);
}
void WritePersonData(string& name, string& height, string& weight, const unsigned short* age) {
	cout << "Имя: " << name << endl;
	cout << "Рост: " << height << endl;
	cout << "Вес: " << weight << endl;
	cout << "Возраст: " << (*age) << endl;
	cout << "Зарплата: " << salary_str << endl;
}
int main() {

	unsigned short weight, age;
	string name, height_str = "", weight_str = "";
	double salary;
	
	ReadPersonData(name, age, salary);
	ReadPersonData(name, age, height, weight);
	height_str = to_string(height);
	weight_str = to_string(weight);
	salary_str = to_string(salary);
	WritePersonData(name, height_str, weight_str, &age);
}

