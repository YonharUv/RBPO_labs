#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;

extern unsigned short height;
extern string salary_str;

unsigned short ReadPersonAge();
string ReadPersonName();
void ReadPersonHeight();
void ReadPersonWeight(unsigned short&);
void ReadPersonSalary(double*);
void ReadPersonData(string&, unsigned short&, double&);
void ReadPersonData(string&, unsigned short&, unsigned short&, unsigned short&);
void WritePersonData(string&, string&, string&, const unsigned short*);
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