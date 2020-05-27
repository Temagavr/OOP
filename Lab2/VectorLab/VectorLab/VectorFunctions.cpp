#include "VectorFunctions.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>

void ReadElements(istream& input, vector<double>& vect)
{
	double temp;
	while (input >> temp) {
		vect.push_back(temp);
	}
}

double FindMinElement(vector<double>& vect)
{
	double min = 999999999.0;
	for (unsigned int i = 0; i < vect.size(); ++i) {
		if (min > vect[i]) {
			min = vect[i];
		}
	}
	return min;
}

void MultiplyVectorByNumber(vector<double>& vect, double num)
{
	transform(vect.begin(), vect.end(), vect.begin(), [&num](auto& temp) {return temp * num;});
	/*for (unsigned int i = 0; i < vect.size(); ++i) {
		vect[i] *= num;
	}*/
}

void PrintSortedVector(vector<double>& vect, ostream& output)
{
	sort(vect.begin(), vect.end());
	for (unsigned int i = 0; i < vect.size(); ++i) {
		if (i != vect.size() - 1) {
			output << setprecision(3) << vect[i] << " ";
		}
		else {
			output << setprecision(3) << vect[i];
		}
	}
}
