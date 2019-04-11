#pragma once
#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>
#include "Person.h"

class Doctor :public Person
{
public:
	//******************************Конструктуры******************************
	Doctor();//Конструктор по умолчанию
	Doctor(std::string _name, std::string _surname, int age, std::string _department, std::string _skill, int _stage);//конструктор инициализации
	Doctor(const Doctor&);//конструктор копирования
	virtual ~Doctor(); //деструктор

					   //******************************Функции******************************
	std::string getskill() const;	//специальность
	int getstage() const;			//стаж

	void setskill(std::string _skill);	//Изменение специальности
	void setstage(int _stage);			//изменение стажа

	Doctor & operator = (const Doctor&);
	Doctor& operator++ ();//перегрузка инкремента (префикс)
	Doctor operator++ (int);//перегрузка инкремента (постфикс)
	Doctor& operator-- ();//перегрузка дикремента (префикс)
	Doctor operator-- (int);//перегрузка дикремента (постфикс)

							//************************************************************
	virtual void Print(std::ostream&out) const;//виртуальная функция печати
	virtual void Change(std::istream&in);//виртуальная функция
										 //************************************************************

private:
	std::string skill;
	int  stage;
};

std::ostream & operator << (std::ostream&out, const Doctor &right);
std::istream & operator >> (std::istream&in, Doctor & right);



#endif // !DOCTOR_H
