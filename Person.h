#pragma once
#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
	//******************************������������******************************
	Person();//����������� �� ���������
	Person(std::string _name, std::string _surname, int _age, std::string _department);//����������� �������������
	Person(const Person&);//����������� �����������
	virtual ~Person();//����������

					  //******************************�������******************************
	std::string getname() const;//���
	std::string getsurname() const;//�������
	int getage() const;//�������
	std::string getdepartment() const;//���������

	void setname(std::string _name);//��������� �����
	void setsurname(std::string _surname);//��������� �������
	void setage(int _age);//��������� ��������
	void setdepartment(std::string _department);//��������� ���������

												//************************************************************
	virtual void Print(std::ostream&out) const;//����������� ������� ������
	virtual void Change(std::istream&in);//����������� �������
										 //************************************************************

										 //******************************������������� ���������******************************
	Person & operator = (const Person &);//���������� ��������� �����
	bool operator== (const Person&right) const;//���������� ��������� ���������
	bool operator!= (const Person&right) const;//���������� ��������� �� �����

private:
	std::string name;
	std::string surname;
	int age;
	std::string department;
};

std::ostream & operator << (std::ostream&out, Person &right);		//��������� � �����
std::istream & operator >> (std::istream&in, const Person &right);	//����� �� ������

#endif // !PERSON_H
