#pragma once
#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
	//******************************Конструктуры******************************
	Person();//Конструктор по умолчанию
	Person(std::string _name, std::string _surname, int _age, std::string _department);//конструктор инициализации
	Person(const Person&);//Конструктор копирования
	virtual ~Person();//Деструктор

					  //******************************Функция******************************
	std::string getname() const;//имя
	std::string getsurname() const;//фамилия
	int getage() const;//возраст
	std::string getdepartment() const;//отделение

	void setname(std::string _name);//изменение имени
	void setsurname(std::string _surname);//изменение фамилии
	void setage(int _age);//изменение возраста
	void setdepartment(std::string _department);//изменение отделения

												//************************************************************
	virtual void Print(std::ostream&out) const;//виртуальная функция печати
	virtual void Change(std::istream&in);//виртуальная функция
										 //************************************************************

										 //******************************Перегруженные операторы******************************
	Person & operator = (const Person &);//перегрузка оператора равно
	bool operator== (const Person&right) const;//перегрузка оператора сравнение
	bool operator!= (const Person&right) const;//перегрузка оператора не равно

private:
	std::string name;
	std::string surname;
	int age;
	std::string department;
};

std::ostream & operator << (std::ostream&out, Person &right);		//поместить в поток
std::istream & operator >> (std::istream&in, const Person &right);	//взять из потока

#endif // !PERSON_H
