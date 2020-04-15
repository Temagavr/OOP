#include <iostream>
#include <sstream>
#include <string>
#define CATCH_CONFIG_MAIN

#include "../../../catch2/catch.hpp"
#include "../TrimStream/TrimFunctions.h"

SCENARIO("TrimBlanksTest") {
	string temp = "";
	WHEN("String is empty") {
		THEN("Return empty string") {
			string trimed = TrimBlanks(temp);
			CHECK(trimed == "");
		}
	}

	WHEN("String have not extra blanks") {
		temp = "1 2 3";
		THEN("Return same string") {
			string trimed = TrimBlanks(temp);
			CHECK(trimed == "1 2 3");
		}
	}

	WHEN("String have extra blanks in the beggining") {
		temp = "  \t   1 2 3";
		THEN("Return string without extra blanks") {
			string trimed = TrimBlanks(temp);
			CHECK(trimed == "1 2 3");
		}
	}

	WHEN("String have extra blanks in the ending") {
		temp = "1 2 3  \t   ";
		THEN("Return string without extra blanks") {
			string trimed = TrimBlanks(temp);
			CHECK(trimed == "1 2 3");
		}
	}

	WHEN("String have extra blanks") {
		temp = "  \t\t\t   1 2 3  \t   ";
		THEN("Return string without extra blanks") {
			string trimed = TrimBlanks(temp);
			CHECK(trimed == "1 2 3");
		}
	}
}

SCENARIO("TrimStreamTest") {
	ostringstream output;
	
	WHEN("Input is empty string") {
		istringstream input("");
		THEN("Output is empty string") {
			TrimStream(input, output);
			CHECK(input.eof());
			CHECK(output.str() == "");
		}
	}

	WHEN("Input have one string") {
		istringstream input("   132    \n");
		THEN("Output have trimed string") {
			TrimStream(input, output);
			CHECK(input.eof());
			CHECK(output.str() == "132\n");
		}
	}

	WHEN("Input have several strings") {
		istringstream input("   132    \n\t\tabcdf  ds dsd \t\n");
		THEN("Output have several trimed strings") {
			TrimStream(input, output);
			CHECK(input.eof());
			CHECK(output.str() == "132\nabcdf  ds dsd\n");
		}
	}
}