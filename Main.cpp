#include <iostream>
#include <string>
#include "Person.h"
#include "Doctor.h"
#include "Patient.h"
#include <fstream>
#include <vector>
#include <conio.h>

using namespace std;
vector <Doctor> doctors;
vector <Patient> patients;

void admin_menu()
{
	int enter = 0;
	string password;
	string keys = "Hospital";
	cout << "*******************************************************************************" << endl;
	cout << "Enter with password: ";
	int ch = 0;
	while (true)
	{
		ch = _getch();
		if (ch == 13)
		{
			break;
		}

		if (ch == 8)
		{
			cout << (char)8 << ' ' << char(8);
			if (!password.empty())
				password.erase(password.length() - 1);
		}
		else
		{
			cout << '*';
			password += (char)ch;
		}
	}
	cout << endl;
	cout << "*******************************************************************************" << endl << endl << endl;
	if (password == keys)
	{
		while (enter != 12)
		{
			cout << "*******************************************************************************" << endl;
			cout << "Your action?" << endl;
			cout << "1. Print all the doctors" << endl;
			cout << "2. Print all the patients" << endl;
			cout << "3. Add doctor" << endl;
			cout << "4. Delete doctor" << endl;
			cout << "5. Add patient" << endl;
			cout << "6. Delete patient" << endl;
			cout << "7. To change the data of the doctor" << endl;
			cout << "8. To change the data of the patient" << endl;
			cout << "9. Search doctor" << endl;
			cout << "10. Search patient" << endl;
			cout << "11. Transfer the patient to another Department" << endl;
			cout << "12. Exit" << endl;
			cout << "*******************************************************************************" << endl;
			cin >> enter;
			cin.ignore();

			switch (enter)
			{
			case 1:
			{
				cout << "*******************************************************************************" << endl;
				cout << "Print all the doctors" << endl;
				for (int i = 0; i < doctors.size(); i++)
					cout << doctors[i] << endl;
				system("pause");
				cout << "*******************************************************************************" << endl << endl;
				break;
			}
			case 2:
			{
				cout << "*******************************************************************************" << endl;
				cout << "Print all the patients" << endl;
				for (int i = 0; i < patients.size(); i++)
					cout << patients[i] << endl;
				system("pause");
				cout << "*******************************************************************************" << endl << endl << endl;
				break;
			}
			case 3:
			{
				cout << "*******************************************************************************" << endl;
				cout << "Add doctor" << endl;
				Doctor doc;
				cin >> doc;
				doctors.push_back(doc);
				system("pause");
				cout << "*******************************************************************************" << endl << endl;
				break;

			}
			case 4:
			{
				cout << "*******************************************************************************" << endl;
				cout << "Delete doctor" << endl;
				string name, surname;
				int age;
				cout << "Enter with name,surname and age." << endl;
				cout << "Enter name: "; cin >> name;
				cout << "Enter surname: "; cin >> surname;
				cout << "Enter age: "; cin >> age;
				cin.ignore();
				int doctorIdx = -1;
				for (size_t i = 0; i < doctors.size(); i++)
				{
					if (doctors[i].getsurname() == surname && doctors[i].getname() == name && doctors[i].getage() == age)
					{
						doctorIdx = i; break;
					}
				}
				if (doctorIdx >= 0)
				{
					doctors.erase(doctors.begin() + doctorIdx);
					cout << "Delete complete!" << endl;
				}
				else
					cout << "This request cannot be processed!" << endl;
				system("pause");
				cout << "*******************************************************************************" << endl << endl << endl;
				break;
			}
			case 5:
			{
				cout << "*******************************************************************************" << endl;
				cout << "Add patient" << endl;
				Patient pat;
				cin >> pat;
				patients.push_back(pat);
				system("pause");
				cout << "*******************************************************************************" << endl << endl << endl;
				break;
			}
			case 6:
			{
				cout << "*******************************************************************************" << endl;
				cout << "Delete patient" << endl;
				string name, surname; int age;
				cout << "Enter with name,surname and age." << endl;
				cout << "Enter name: "; cin >> name;
				cout << "Enter surname: "; cin >> surname;
				cout << "Enter age: "; cin >> age;
				cin.ignore();
				int patientIdx = -1;
				for (size_t i = 0; i < patients.size(); i++)
				{
					if (patients[i].getsurname() == surname && patients[i].getname() == name && patients[i].getage() == age)
					{
						patientIdx = i; break;
					}
				}
				if (patientIdx >= 0)
				{
					patients.erase(patients.begin() + patientIdx);
					cout << "Delete complete!" << endl;
				}
				else
					cout << "This request cannot be processed!" << endl;
				system("pause");
				cout << "*******************************************************************************" << endl << endl << endl;
				break;
			}
			case 7:
			{
				cout << "*******************************************************************************" << endl;
				cout << "To change the data of the doctor" << endl;
				string name, surname; int age;
				cout << "Enter with Bame,Surname and Age" << endl;
				cout << "Enter name: "; cin >> name;
				cout << "Enter surname: "; cin >> surname;
				cout << "Enter age: "; cin >> age;
				cin.ignore();
				int doctorIdx = -1;
				for (size_t i = 0; i < doctors.size(); i++)
				{
					if (doctors[i].getsurname() == surname && doctors[i].getname() == name && doctors[i].getage() == age)
					{
						doctorIdx = i; break;
					}
				}
				if (doctorIdx >= 0)
				{
					int chose = 0;
					cout << "What do you want to change? (Name ,Surname, Age, Department, Skill and Stage)" << endl;
					cout << "1.Name || 2.Surname || 3.Age	|| 4.Department || 5.Skill || 6.Stage " << endl;
					cout << "Your choice?: "; cin >> chose; cin.ignore();
					string choise = "";
					int chooise = 0;
					switch (chose)
					{
					case 1:
					{
						cout << "Enter new Name: "; cin >> choise; doctors[doctorIdx].setname(choise);
						break;
					}
					case 2:
					{
						cout << "Enter new Surname: "; cin >> choise; doctors[doctorIdx].setsurname(choise);
						break;
					}
					case 3:
					{
						cout << "Enter new Age: "; cin >> chooise; doctors[doctorIdx].setage(chooise);
						break;
					}
					case 4:
					{
						cout << "Enter new Department: "; cin >> choise; doctors[doctorIdx].setdepartment(choise);
						break;
					}
					case 5:
					{
						cout << "Enter new Skill: "; cin >> choise; doctors[doctorIdx].setskill(choise);
						break;
					}
					case 6:
					{
						cout << "Enter new Stage: "; cin >> chooise; doctors[doctorIdx].setstage(chooise);//исправить
						break;
					}
					}
				}
				else
					cout << "This request cannot be processed!" << endl;
				system("pause");
				cout << "*******************************************************************************" << endl << endl << endl;
				break;
			}
			case 8:
			{
				cout << "*******************************************************************************" << endl;
				cout << "To change the data of the patient" << endl;
				string name, surname; int age;
				cout << "Enter with name,surname and age." << endl;
				cout << "Enter name: "; cin >> name;
				cout << "Enter surname: "; cin >> surname;
				cout << "Enter age: "; cin >> age;
				cin.ignore();
				int patientIdx = -1;
				for (size_t i = 0; i < patients.size(); i++)
				{
					if (patients[i].getsurname() == surname && patients[i].getname() == name && patients[i].getage() == age)
					{
						patientIdx = i; break;
					}
				}
				if (patientIdx >= 0)
				{
					int chose = 0;
					cout << "What do you want to change? (Name ,Surname, Age, Department, Skill and Stage)" << endl;
					cout << "1.Name || 2.Surname || 3.Age	|| 4.Department || 5.Diagnose || 6.Chamber " << endl;
					cout << "Your choice?: "; cin >> chose; cin.ignore();
					string choise = "";
					int chooise = 0;
					switch (chose)
					{
					case 1:
					{
						cout << "Enter new Name: "; cin >> choise; patients[patientIdx].setname(choise);
						break;
					}
					case 2:
					{
						cout << "Enter new Surname: "; cin >> choise; patients[patientIdx].setsurname(choise);
						break;
					}
					case 3:
					{
						cout << "Enter new Age: "; cin >> chooise; patients[patientIdx].setage(chooise);
						break;
					}
					case 4:
					{
						cout << "Enter new Department: "; cin >> choise; patients[patientIdx].setdepartment(choise);
						break;
					}
					case 5:
					{
						cout << "Enter new Skill: "; cin >> choise; patients[patientIdx].setdiagnose(choise);
						break;
					}
					case 6:
					{
						cout << "Enter new Chamber: "; cin >> chooise; patients[patientIdx].setchamber(chooise);
						break;
					}
					}
				}
				else
					cout << "This request cannot be processed!" << endl;
				system("pause");
				cout << "*******************************************************************************" << endl << endl << endl;
				break;
			}
			case 9:
			{
				cout << "*******************************************************************************" << endl;
				cout << "Search doctor" << endl;
				string Surname;
				cout << "Enter Surname: "; cin >> Surname;
				cin.ignore();
				int doctorIdx = -1;
				for (size_t i = 0; i < doctors.size(); i++)
				{
					if (doctors[i].getsurname() == Surname)
					{
						doctorIdx = i; break;
					}
				}
				if (doctorIdx >= 0)
				{
					cout << doctors[doctorIdx];
				}
				else
					cout << "This request cannot be processed!" << endl;
				system("pause");
				cout << "*******************************************************************************" << endl << endl << endl;
				break;
			}
			case 10:
			{
				cout << "*******************************************************************************" << endl;
				cout << "Search patient:" << endl;
				string Surname;
				cout << "Enter Surname: "; cin >> Surname;
				cin.ignore();
				int patientIdx = -1;
				for (size_t i = 0; i < patients.size(); i++)
				{
					if (patients[i].getsurname() == Surname)
					{
						patientIdx = i; break;
					}
				}
				if (patientIdx >= 0)
					cout << patients[patientIdx];
				else
					cout << "This request cannot be processed!" << endl;
				system("pause");
				cout << "*******************************************************************************" << endl << endl << endl;
				break;
			}
			case 11:
			{
				cout << "*******************************************************************************" << endl;
				cout << "Transfer the patient to another Department" << endl;
				cout << "Enter the patient you want to Transfere (Name,Surname and Age)" << endl;
				string Name, Surname; int Age;
				cout << "Enter Name: "; cin >> Name;
				cout << "Enter Surname: "; cin >> Surname;
				cout << "Enter Age: "; cin >> Age;
				cin.ignore();
				int patientIdx = -1;
				for (size_t i = 0; i < patients.size(); i++)
				{
					if (patients[i].getsurname() == Surname && patients[i].getname() == Name && patients[i].getage() == Age)
					{
						patientIdx = i; break;
					}
				}
				if (patientIdx >= 0)
				{
					string department, diagnose;
					cout << "Enter new department: "; cin >> department; int ID = -1;
					for (int i = 0; i < doctors.size(); i++)
						if (doctors[i].getdepartment() == department)
						{
							ID = i;
							cout << "Department found. Do you want to change the diagnosis (y/n)? " ;
							patients[patientIdx].setdepartment(department);
							string chose; cin >> chose;
							if (chose == "y")
							{
								cout << "Enter new diagnose: "; cin >> diagnose;
								patients[patientIdx].setdiagnose(diagnose);
								
							}
							break;
						}
					if (ID == -1)
					{
						cout << "Transfer not found, translation impossible!" << endl;
						break;
					}
				}
				else
					cout << "This request cannot be processed!" << endl;
				system("pause");
				cout << "*******************************************************************************" << endl << endl;
				break;
			}
			}

		}
	}
	else
	{
		cout << "You failed log in." << endl;
		cout << endl;
	}
	cout << endl;
}

void doctor_menu()
{
	int enter = 0;
	string name, surname;
	int age;
	cout << "*******************************************************************************" << endl;
	cout << "Enter with Name, Surname and Age" << endl;
	cout << "Enter Name: "; cin >> name;
	cout << "Enter Surname: "; cin >> surname;
	cout << "Enter Age: "; cin >> age;
	cout << "*******************************************************************************" << endl << endl;
	cin.ignore();
	int doctorIdx = -1;
	for (size_t i = 0; i < doctors.size(); i++)
	{
		if (doctors[i].getsurname() == surname && doctors[i].getname() == name && doctors[i].getage() == age)
		{
			doctorIdx = i; break;
		}
	}
	if (doctorIdx >= 0)
	{
		while (enter != 7)
		{
			cout << "*******************************************************************************" << endl;
			cout << "Your action?" << endl;
			cout << "1. To withdraw all of  their patient" << endl;
			cout << "2. Add patient" << endl;
			cout << "3. Delete patient" << endl;
			cout << "4. To change your details" << endl;
			cout << "5. Change patient's diagnose" << endl;
			cout << "6. Transfer the patient to another Department" << endl;
			cout << "7. Exit" << endl;
			cout << "*******************************************************************************" << endl;
			cin >> enter;
			cin.ignore();
			cout << endl;

			switch (enter)
			{
			case 1:
			{
				cout << "*******************************************************************************" << endl;
				cout << "To print all of  their patient" << endl;
				int id = -1;
				for (size_t i = 0; i < patients.size(); i++)
				{
					if (patients[i].getdepartment() == doctors[i].getdepartment())
					{
						id = i;
						cout << patients[i] << endl;
					}
				}
				if (id == -1)
				{
					cout << "There are no Patients!" << endl;
				}
				system("pause");
				cout << "*******************************************************************************" << endl << endl;
				break;
			}
			case 2:
			{
				cout << "*******************************************************************************" << endl;
				cout << "Add patient" << endl;
				Patient pat;
				cin >> pat;
				patients.push_back(pat);
				system("pause");
				cout << "*******************************************************************************" << endl << endl;
				break;
			}
			case 3:
			{
				cout << "*******************************************************************************" << endl;
				cout << "Delete patient!" << endl;
				string name, surname; int age;
				cout << "Enter with name,surname and age." << endl;
				cout << "Enter name: "; cin >> name;
				cout << "Enter surname: "; cin >> surname;
				cout << "Enter age: "; cin >> age;
				cin.ignore();
				int patientIdx = -1;
				for (size_t i = 0; i < patients.size(); i++)
				{
					if (patients[i].getsurname() == surname)
					{
						patientIdx = i; break;
					}
				}
				if (patientIdx >= 0)
				{
					patients.erase(patients.begin() + patientIdx);
					cout << "Delete complete!" << endl;
				}
				else
					cout << "This request cannot be processed!" << endl;
				system("pause");
				cout << "*******************************************************************************" << endl << endl;
				break;
			}
			case 4:
			{
				cout << "*******************************************************************************" << endl;
				cout << "To change your details" << endl;
				int choise = 0;
				cout << "What do you want to change?" << endl;
				cout << "1.Name		2.Surname		3.Age " << endl;
				cout << "Your choice?: "; cin >> choise; cin.ignore();
				switch (choise)
				{
				case 1:
				{
					string Name = "";
					cout << "Enter new Name: ";
					cin >> Name;
					doctors[doctorIdx].setname(Name);
					break;
				}
				case 2:
				{
					string Surname = "";
					cout << "Enter new Surame: ";
					cin >> Surname;
					doctors[doctorIdx].setsurname(Surname);
					break;
				}
				case 3:
				{
					int Age = 0;
					cout << "Enter new Age: ";
					cin >> Age;
					doctors[doctorIdx].setage(Age);
					break;
				}
				}
				system("pause");
				cout << "*******************************************************************************" << endl << endl;
				break;
			}
			case 5:
			{
				cout << "*******************************************************************************" << endl;
				cout << "Change patient's Diagnose" << endl;
				cout << "Enter the patient you want to Change (Name,Surname and Age)" << endl;
				string Name, Surname; int Age;
				cout << "Enter Name: "; cin >> Name;
				cout << "Enter Surname: "; cin >> Surname;
				cout << "Enter Age: "; cin >> Age;
				cin.ignore();
				int patientIdx = -1;
				for (size_t i = 0; i < patients.size(); i++)
				{
					if (patients[i].getsurname() == surname && patients[i].getname() == name && patients[i].getage() == age)
					{
						patientIdx = i; break;
					}
				}
				if (patientIdx >= 0)
				{
					string diagnose;
					cout << "Enter new diagnose: "; cin >> diagnose;
					patients[patientIdx].setdiagnose(diagnose);
				}
				else
					cout << "This request cannot be processed!" << endl;
				system("pause");
				cout << "*******************************************************************************" << endl << endl;
				break;
			}
			case 6:
			{
				cout << "*******************************************************************************" << endl;
				cout << "Transfer the patient to another Department" << endl;
				cout << "Enter the patient you want to Transfere (Name,Surname and Age)" << endl;
				string Name, Surname; int Age;
				cout << "Enter Name: "; cin >> Name;
				cout << "Enter Surname: "; cin >> Surname;
				cout << "Enter Age: "; cin >> Age;
				cin.ignore();
				int patientIdx = -1;
				for (size_t i = 0; i < patients.size(); i++)
				{
					if (patients[i].getsurname() == Surname && patients[i].getname() == Name && patients[i].getage() == Age)
					{
						patientIdx = i; break;
					}
				}
				if (patientIdx >= 0 && doctors[doctorIdx].getdepartment() == patients[patientIdx].getdepartment())
				{
					string department, diagnose;
					cout << "Enter new department: "; cin >> department; int ID = -1;
					for (int i = 0; i < doctors.size(); i++)
						if (doctors[i].getdepartment() == department)
						{
							ID = i;
							cout << "Department found. Do you want to change the diagnosis (y/n)? ";
							patients[patientIdx].setdepartment(department);
							string chose; cin >> chose;
							if (chose == "y")
							{
								cout << "Enter new diagnose: "; cin >> diagnose;
								patients[patientIdx].setdiagnose(diagnose);

							}
							break;
						}
					if (ID == -1)
					{
						cout << "Transfer not found, translation impossible!" << endl;
					}
				}
				else
					cout << "Translation failed. Such a patient is not found or it is not your patient" << endl;
				system("pause");
				cout << "*******************************************************************************" << endl << endl;
				break;
			}
			}
		}
	}
	else
	{
		cout << "You failed log in." << endl;
		cout << endl;
	}
	cout << endl;
}


void patient_menu()
{
	int enter = 0;
	string name, surname; int age;
	cout << "*******************************************************************************" << endl;
	cout << "Enter with Name, Surname and Age" << endl;
	cout << "Enter Name: "; cin >> name;
	cout << "Enter Surname: "; cin >> surname;
	cout << "Enter Age: "; cin >> age;
	cout << "*******************************************************************************" << endl << endl;
	cin.ignore();
	int patientIdx = -1;
	for (size_t i = 0; i < patients.size(); i++)
	{
		if (patients[i].getsurname() == surname && patients[i].getname() == name && patients[i].getage() == age)
		{
			patientIdx = i; break;
		}
	}
	if (patientIdx >= 0)
	{
		while (enter != 3)
		{
			cout << "*******************************************************************************" << endl;
			cout << "Your action?" << endl;
			cout << "1. Withdraw your doctor" << endl;
			cout << "2. To change your details" << endl;
			cout << "3. Exit" << endl;
			cout << "*******************************************************************************" << endl << endl;
			cin >> enter;
			cin.ignore();
			cout << endl;

			switch (enter)
			{
			case 1:
			{
				cout << "*******************************************************************************" << endl;
				cout << "Withdraw your doctor" << endl;
				int doctorIdx = -1;
				for (size_t i = 0; i < doctors.size(); i++)
				{
					if (patients[i].getdepartment() == doctors[i].getdepartment())
					{
						doctorIdx = i; break;
					}
				}
				if (doctorIdx >= 0)
				{
					cout << doctors[doctorIdx];
				}
				else
					cout << "This request cannot be processed!" << endl;
				system("pause");
				cout << "*******************************************************************************" << endl << endl;
				break;
			}
			case 2:
			{
				cout << "*******************************************************************************" << endl;
				cout << "To change your details" << endl;
				int choise = 0;
				cout << "What do you want to change?" << endl;
				cout << "1.Name		2.Surname		3.Age " << endl;
				cout << "Your choice?: "; cin >> choise; cin.ignore();
				switch (choise)
				{
				case 1:
				{
					string Name = "";
					cout << "Enter new Name: ";
					cin >> Name;
					patients[patientIdx].setname(Name);
					break;
				}
				case 2:
				{
					string Surname = "";
					cout << "Enter new Surname: ";
					cin >> Surname;
					patients[patientIdx].setname(Surname);
					break;
				}
				case 3:
				{
					int Age = 0;
					cout << "Enter new Age: ";
					cin >> Age;
					cin.ignore();
					patients[patientIdx].setage(Age);
					break;
				}
				}
				system("pause");
				cout << "*******************************************************************************" << endl << endl;
				break;
			}
			}


		}
	}
	else
	{
		cout << "You failed log in." << endl;
		cout << endl;
	}
	cout << endl;
}



int main()
{
	ifstream fin("Doctor.txt");

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			Doctor doc;
			fin >> doc;
			doctors.push_back(doc);
		}
	fin.close();
	}
	
	ifstream fil("Patient.txt");
	if (fil.is_open())
	{
		while (!fil.eof())
		{
			Patient pat;
			fil >> pat;
			patients.push_back(pat);
		}
		fil.close();
	}
	
	int enter = 0;
	int output = 4;
	while (output != 0)
	{
		enter = 0;
		bool check = true;
		cout << "*******************************************************************************" << endl;
		cout << "Login in as" << endl;
		cout << "1. Admin     2.Doctor     3.Patient" << endl;
		cout << "If you want to get EXIT: 0" << endl;
		cout << "*******************************************************************************" << endl;
		cout << endl;
		cin >> output;
		cin.ignore();

		if (output == 1)
			admin_menu();
		if (output == 2)
			doctor_menu();
		if (output == 3)
			patient_menu();
	}

	ofstream outfile("Doctor.txt");
	if (outfile.is_open())
	{
		for (size_t i = 0; i < doctors.size(); i++)
		{
			outfile << doctors[i];
		}
	outfile.close();
	}
	
	ofstream out("Patient.txt");
	if (out.is_open())
	{
		for (size_t i = 0; i < patients.size(); i++)
		{
			out << patients[i];
		}
		out.close();
	}
	return 0;
}