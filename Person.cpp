#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

//******************************Конструкторы******************************
Person::Person() :name(""), surname(""), age(0), department("") {}


Person::Person(string _name, string _surname, int _age, string _department) :
	name(_name), surname(_surname), age(_age), department(_department) {}


Person::Person(const Person&p) :
	name(p.name), surname(p.surname), age(p.age), department(p.department) {}

Person::~Person() {} //Деструктор (удаление)


					 //******************************Заполнение полей******************************
string Person::getname() const			//Имя
{
	return name;
}
string Person::getsurname() const		//Фамилий
{
	return surname;
}
int Person::getage() const				//Возраст
{
	return age;
}
string Person::getdepartment() const	//Отделение
{
	return department;
}

//******************************Изменение полей******************************
void Person::setname(std::string _name)					//Изменить имя
{
	name = _name;
}
void Person::setsurname(std::string _surname)			//Изменить фамилию
{
	surname = _surname;
}
void Person::setage(int _age)							//Изменить возраст
{
	age = _age;
}
void Person::setdepartment(std::string _department)	//Изменить отделение
{
	department = _department;
}

//******************************Печать******************************
void Person::Print(ostream&out) const
{

	if (&out == &std::cout)
	{
		out << "Name: " << name.c_str() << endl;
		out << "Surname: " << surname.c_str() << endl;
		out << "Age: " << age << endl;
		out << "Department: " << department.c_str() << endl;
	}
	else
	{
		out<<" " << name.c_str() << endl << surname.c_str() << endl << age << endl << department.c_str() << endl;
	}
}

void Person::Change(istream&in)
{
	if (&in == &std::cin)
	{
		string temp;
		cout << "Enter name: ";
		getline(in, temp);
		setname(temp);
		cout << "Enter surname: ";
		getline(in, temp);
		setsurname(temp);
		cout << "Enter age: ";
		int a;
		in >> a;
		setage(a);
		cin.ignore();
		cout << "Enter department: ";
		getline(in, temp);
		setdepartment(temp);
	}
	else
	{
		string temp;
		getline(in, temp);
		setname(temp);
		getline(in, temp);
		setsurname(temp);
		int a;
		in >> a;
		setage(a);
		in.ignore();
		getline(in, temp);
		setdepartment(temp);
	}
}

//******************************Перегрузка******************************
bool Person::operator!= (const Person&right) const
{
	return !(*this == right);
}


bool Person::operator== (const Person&right) const
{
	if (name == right.name && surname == right.surname && age == right.age)
		return true;
	return false;
}


Person&Person::operator=(const Person&right)
{
	if (this != &right)
	{
		name = right.name;
		surname = right.surname;
		age = right.age;
		department = right.department;
	}
	return *this;
}

ostream & operator << (ostream&out, const Person &right)
{
	right.Print(out);
	return out;
}

istream & operator >> (std::istream&in, Person&right)
{
	right.Change(in);
	return in;
}