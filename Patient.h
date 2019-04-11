#pragma once
#ifndef PATIENT_H
#define PATIENT_H
#include "Person.h"


class Patient :public Person
{
public:
	//******************************������������******************************
	Patient();//������������ �� ���������
	Patient(std::string _name, std::string _surname, int _age, std::string _department,
		std::string _diagnose, int _chamber);//���������� �������������
	Patient(const Patient&);//����������� �����������
	virtual ~Patient();//����������

					   //******************************�������******************************
	std::string getdiagnose() const;	//�������
	int getchamber() const;				//������

	void setdiagnose(std::string _diagnose);	//��������� ��������
	void setchamber(int _chamber);				//��������� ������

	Patient & operator = (const Patient&);

	//************************************************************
	virtual void Print(std::ostream&out) const;	//����������� ������� ������
	virtual void Change(std::istream&in);		//����������� �������
	//************************************************************
private:
	std::string diagnose;
	int chamber;
};


std::ostream & operator << (std::ostream&out, const Patient &right);
std::istream & operator >> (std::istream&in, Patient & right);


#endif // !PATIENT_H
