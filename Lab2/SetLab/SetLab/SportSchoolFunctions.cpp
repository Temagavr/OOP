#include "SportSchoolFunctions.h"
#include <set>
#include <iostream>
#include <fstream> 
#include <iterator>

void ReadFiles(vector<string> sectionsList, set<string>& studentsList)
{
	setlocale(LC_ALL, "Russian");
	for(int i = 0; i != sectionsList.size(); ++i){
		ifstream fin;
		fin.open(sectionsList[i]);
		CreateStudentsList(fin, studentsList);
		fin.close();
	}
}

void CreateStudentsList(istream& input, set<string>& studentsList) {
	string student;
	while (input >> student) {
		if (studentsList.find(student) == studentsList.end()) {
			studentsList.insert(student);
		}
	}
}

void PrintStudentsList(set<string>& studentsList, ostream& output)
{
	//copy(studentsList.begin(), studentsList.end(), ostream_iterator<string>(output, "\n"));
	set<string>::iterator i = studentsList.begin();
	for (i; i != studentsList.end();++i) {
		if (i != (--(studentsList.end()))) {
			output << *i << endl;
		}
		else {
			output << *i;
		}
		//output << *i << endl;
	}
}



/*
void UpdateStudentsList(set<string> studentsList, string student)
{
	if (studentsList.find(student) == studentsList.end()) {
		studentsList.insert(student);
	}
}*/
