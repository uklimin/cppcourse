#pragma once
#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>
#include "Person.h"

class Doctor :public Person
{
public:
	//******************************������������******************************
	Doctor();//����������� �� ���������
	Doctor(std::string _name, std::string _surname, int age, std::string _department, std::string _skill, int _stage);//����������� �������������
	Doctor(const Doctor&);//����������� �����������
	virtual ~Doctor(); //����������

					   //******************************�������******************************
	std::string getskill() const;	//�������������
	int getstage() const;			//����

	void setskill(std::string _skill);	//��������� �������������
	void setstage(int _stage);			//��������� �����

	Doctor & operator = (const Doctor&);
	Doctor& operator++ ();//���������� ���������� (�������)
	Doctor operator++ (int);//���������� ���������� (��������)
	Doctor& operator-- ();//���������� ���������� (�������)
	Doctor operator-- (int);//���������� ���������� (��������)

							//************************************************************
	virtual void Print(std::ostream&out) const;//����������� ������� ������
	virtual void Change(std::istream&in);//����������� �������
										 //************************************************************

private:
	std::string skill;
	int  stage;
};

std::ostream & operator << (std::ostream&out, const Doctor &right);
std::istream & operator >> (std::istream&in, Doctor & right);



#endif // !DOCTOR_H
