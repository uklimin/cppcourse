#include <iostream>
#include <string>
#include "Person.h"
#include "Doctor.h"
#include <fstream>
using namespace std;

Doctor::Doctor() :Person(), skill(""), stage(0) {}

Doctor::Doctor(string _name, string _surname, int _age, string _department, string _skill, int _stage) :
	Person(_name, _surname, _age, _department), skill(_skill), stage(_stage) {}

Doctor::~Doctor() {} //деструктор

					 //******************************Заполнение полей******************************
string Doctor::getskill() const		//специальность
{
	return skill;
}
int Doctor::getstage() const		//стаж
{
	return stage;
}

//******************************Изменение полей******************************
void Doctor::setskill(std::string _skill)	//изменение специальности
{
	skill = _skill;
}
void Doctor::setstage(int _stage)			//изменение стажа
{
	stage = _stage;
}


Doctor::Doctor(const Doctor&p)
{
	*this = p;
}

Doctor & Doctor::operator = (const Doctor&p)
{
	if (this != &p)
	{
		Person::operator=(p);
		skill = p.skill;
		stage = p.stage;
	}

	return *this;
}

//************************пергрузка************************************
//увеличение стажа (год)
Doctor&Doctor:: operator++ ()
{
	stage++;
	return *this;
}
Doctor Doctor:: operator++ (int)
{
	Doctor temp(*this);
	++(*this);
	return temp;
}

//уменьшение стажа (год)
Doctor&Doctor:: operator-- ()
{
	stage--;
	return *this;
}

Doctor Doctor:: operator-- (int)
{
	Doctor temp(*this);
	--(*this);
	return temp;
}


void Doctor::Print(ostream&out)const
{
	Person::Print(out);
	if (&out == &std::cout)
	{
		out << "Skill: " << skill.c_str() << endl;
		out << "Stage: " << stage << endl;
	}
	else
	{
		out << skill.c_str() << endl;
		out << stage;
	}
}

void Doctor::Change(istream&in)
{
	Person::Change(in);
	if (&in == &std::cin)
	{
		string temp;
		cout << "Enter skill: ";
		getline(in, temp);
		setskill(temp);
		int a;
		cout << "Enter stage: ";
		in >> a;
		setstage(a);
		cin.ignore();
	}
	else
	{
		string temp;
		getline(in, temp);
		setskill(temp);
		int a;
		in >> a;
		setstage(a);
		in.ignore();
	}
}

ostream & operator << (std::ostream&out, const Doctor &right)
{
	right.Print(out);
	return out;
}

istream & operator >> (std::istream&in, Doctor &right)
{
	right.Change(in);
	return in;
}