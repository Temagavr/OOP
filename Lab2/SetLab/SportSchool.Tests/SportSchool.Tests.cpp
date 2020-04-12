#include <iostream>
#include <sstream>
#include <set>
#include <string>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../SetLab/SportSchoolFunctions.h"

using namespace std;

SCENARIO("CreateStudentsListTests") {
	set<string> studentsList;

	WHEN("Empty input stream") {
		istringstream input("");
		THEN("Empty students list") {
			CreateStudentsList(input, studentsList);
			CHECK(input.eof());
			CHECK(studentsList.size() == 0);
		}
	}

	WHEN("One student is in input") {
		istringstream input("Vova\n");
		THEN("Students list contain one element") {
			CreateStudentsList(input, studentsList);
			CHECK(input.eof());
			CHECK(studentsList.size() == 1);
		}
	}

	WHEN("Several students is in input") {
		istringstream input("Vova\nSasha\nAnton");
		THEN("Students list contains the same elements") {
			CreateStudentsList(input, studentsList);
			CHECK(input.eof());
			CHECK(studentsList.size() == 3);
		}
	}

	WHEN("Input contains duplicates") {
		istringstream input("Vova\nSasha\nAnton\nVova\nSasha\nAnton");
		THEN("Students list contain only unique elements") {
			CreateStudentsList(input, studentsList);
			CHECK(input.eof());
			CHECK(studentsList.size() == 3);
		}
	}
}

SCENARIO("PrintStudentsListTest") {
	set<string> studentsList;
	ostringstream output;

	WHEN("Empty students list") {
		THEN("Empty output") {
			PrintStudentsList(studentsList, output);
			CHECK(output.str() == "");
		}
	}

	WHEN("One student in list") {
		studentsList.insert("Vova");
		THEN("One student in output") {
			PrintStudentsList(studentsList, output);
			CHECK(output.str() == "Vova");
		}
	}

	WHEN("Several students in list") {
		studentsList.insert("Vova");
		studentsList.insert("Anton");
		studentsList.insert("Sasha");
		THEN("The same students in output") {
			PrintStudentsList(studentsList, output);
			CHECK(output.str() == "Anton\nSasha\nVova");
		}
	}
}