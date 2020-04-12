#pragma once
#include <vector>
#include <iostream>
#include <set>

using namespace std;

void ReadFiles(vector<string> sectionsList, set<string>& studentsList);

void CreateStudentsList(istream& input, set<string>& studentsList);

void PrintStudentsList(set<string>& studentsList, ostream& output);

//void UpdateStudentsList(set<string> studentsList, string student);