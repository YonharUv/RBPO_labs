#pragma once

using namespace std;

unsigned short int ReadPersonAge();
string ReadPersonName();
void ReadPersonHeight();
void ReadPersonWeight(unsigned short&);
void ReadPersonSalary(double*);
void ReadPersonData(string&, unsigned short&, double&);
void ReadPersonData(string& , unsigned short&, unsigned short&, unsigned short&);
void WritePersonData(string&, string&, string& , const unsigned short* );