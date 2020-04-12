#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <iterator>
#include "SportSchoolFunctions.h"

using namespace std;

void ParseArgs(char* argv[], int argc, vector<string>& fileNamesList) {
    for (int i = 1; i < argc; ++i) {
        fileNamesList.push_back(argv[i]);
    }
}

int main(int argc, char* argv[])
{
    vector<string> sectionsList;
    if (argc < 1) {
        cout << "No arguments. Usage SportSchool.exe <FirstSection.txt> <SecondSection.txt> ..." << endl;
        return 1;
    }
    else {
        ParseArgs(argv, argc, sectionsList);
    }
    set<string> students;
    ReadFiles(sectionsList, students);
    PrintStudentsList(students, cout);
    return 0;
}
