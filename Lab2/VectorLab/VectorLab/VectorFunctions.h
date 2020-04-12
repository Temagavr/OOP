#pragma once
#include <iostream>
#include <vector>
using namespace std;

void ReadElements(istream& input, vector<double>& vect);

double FindMinElement(vector<double>& vect);

void MultiplyVectorByNumber(vector<double>& vect, double num);

void PrintSortedVector(vector<double>& vect, ostream& output);