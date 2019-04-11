#pragma once
#ifndef PATIENT_H
#define PATIENT_H
#include "Person.h"


class Patient :public Person
{
public:
	//******************************Конструктуры******************************
	Patient();//Конструкторы по умолчанию
	Patient(std::string _name, std::string _surname, int _age, std::string _department,
		std::string _diagnose, int _chamber);//коструктор инициализации
	Patient(const Patient&);//конструктор копирования
	virtual ~Patient();//деструктор

					   //******************************Функция******************************
	std::string getdiagnose() const;	//диагноз
	int getchamber() const;				//палата

	void setdiagnose(std::string _diagnose);	//изменение диагноза
	void setchamber(int _chamber);				//изменение палаты

	Patient & operator = (const Patient&);

	//************************************************************
	virtual void Print(std::ostream&out) const;	//виртуальная функция печати
	virtual void Change(std::istream&in);		//виртуальная функция
	//************************************************************
private:
	std::string diagnose;
	int chamber;
};


std::ostream & operator << (std::ostream&out, const Patient &right);
std::istream & operator >> (std::istream&in, Patient & right);


#endif // !PATIENT_H
