#include <iostream>
#include <string>
#include "Person.h"
#include "Patient.h"
#include <fstream>
using namespace std;

//******************************������������******************************
Patient::Patient() :Person(), diagnose(""), chamber(0) {}

Patient::Patient(std::string _name, string _surname, int _age, string _department, string _diagnose, int _chamber) :
	Person(_name, _surname, _age, _department), diagnose(_diagnose), chamber(_chamber) {}

Patient::Patient(const Patient&p) : Person(p), diagnose(p.diagnose), chamber(p.chamber) {}

Patient::~Patient() {} //����������

					   //******************************���������� �����******************************
string Patient::getdiagnose() const	//���������� ��������
{
	return diagnose;
}
int Patient::getchamber() const		//���������� ������
{
	return chamber;
}

void Patient::setdiagnose(string _diagnose)	//��������� ��������
{
	diagnose = _diagnose;
}
void Patient::setchamber(int _chamber)		//��������� ������
{
	chamber = _chamber;
}

//******************************����������******************************

void Patient::Print(ostream&out) const
{
	Person::Print(out);
	if (&out == &std::cout)
	{
		out << "Diagnose:" << diagnose.c_str() << endl;
		out << "Chamber:" << chamber << endl;
	}
	else
	{

		out << diagnose.c_str() << endl;
		out << chamber;
	}
}

void Patient::Change(istream&in)
{
	Person::Change(in);
	if (&in == &std::cin)
	{
		string temp;
		cout << "Enter diagnose: ";
		getline(in, temp);
		setdiagnose(temp);
		int a;
		cout << "Enter chamber: ";
		in >> a;
		setchamber(a);
		cin.ignore();
	}
	else
	{
		string temp;
		getline(in, temp);
		setdiagnose(temp);
		int a;
		in >> a;
		setchamber(a);
		in.ignore();
	}
}

Patient & Patient::operator = (const Patient&p)
{
	if (this != &p)
	{
		Person::operator=(p);
		diagnose = p.diagnose;
		chamber = p.chamber;
	}

	return *this;
}


ostream & operator << (std::ostream&out, const Patient &right)
{
	right.Print(out);
	return out;
}

istream & operator >> (std::istream&in, Patient & right)
{
	right.Change(in);
	return in;
}
