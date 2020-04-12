#include <iostream>
#include <vector>
#include "VectorFunctions.h"

using namespace std;
int main()
{
	vector<double> inVector;
	ReadElements(cin, inVector);
	if (inVector.size() != 0) {
		double minElem = FindMinElement(inVector);
		MultiplyVectorByNumber(inVector, minElem);
		PrintSortedVector(inVector, cout);
	}
	else {
		cout << "Vector is empty" << endl;
		return 0;
	}
	return 0;
}
