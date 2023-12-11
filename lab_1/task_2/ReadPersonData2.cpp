#include <iostream>
#include "Functions.h"

using namespace std;

unsigned short ReadPersonAge();
string ReadPersonName();
void ReadPersonHeight();
void ReadPersonWeight(unsigned short&);

void ReadPersonData(string& name, unsigned short& age, unsigned short& height, unsigned short& weight) {
	age = ReadPersonAge();
	name = ReadPersonName();
	ReadPersonHeight();
	ReadPersonWeight(weight);
}