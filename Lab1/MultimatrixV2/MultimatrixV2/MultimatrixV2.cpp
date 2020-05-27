#include <iostream>
#include <fstream>
#include <optional>
#include <string>
using namespace std;

const int Size = 3;
const int Simbols_After_Dot = 3;
const int Fractional_Part_Pitch = 10;
const int Rounding_Const = 100;
const string Reading_Error = "Failed to read data from ";
const string Invalid_Args = "Invalid agruments count";
const string Usage_Program = "Usage Multimatrix.exe <matrix1.txt> <matrix2.txt>";

typedef double SquareMatrix[Size][Size];

struct Args {
	string matrix1;
	string matrix2;
};

optional<Args> ParseArgs(int argc, char* argv[]) {
	if (argc != 3) {
		cout << Invalid_Args << endl;
		cout << Usage_Program << endl;
		return nullopt;
	}
	Args args;
	args.matrix1 = argv[1];
	args.matrix2 = argv[2];
	return args;
}

void PrintFractionalPart(double &elem) {
	double fractionalPart;
	fractionalPart = modf(elem, &elem);
	cout << ".";
	if (fractionalPart < 0) { fractionalPart = fractionalPart * -1; }
	for (unsigned int i = 0; i < Simbols_After_Dot; ++i) {
		double temp = 0;
		fractionalPart = modf(fractionalPart * Fractional_Part_Pitch, &temp);
		unsigned int tempInt = temp;
		if (tempInt < 0) {
			tempInt = tempInt * -1;
		}
		cout << tempInt;
	}
}

void PrintSquareMatrix(SquareMatrix mat, int size) {//Вывод матрицы
	for (unsigned int i = 0; i < size;++i) {
		for (unsigned int j = 0; j < size;++j) {
			cout << (int)mat[i][j];
			PrintFractionalPart(mat[i][j]);
			cout << " ";
		}
		cout << endl;
	}
}

void ReadMatrix(ifstream* file, SquareMatrix mat, int size) {//Чтение матрицы
	for (unsigned int i = 0; i < size;++i) {
		for (unsigned int j = 0; j < size;++j) {
			double num;
			*file >> num;
			mat[i][j] = num;
		}
	}
}
//Умножение квадратных матриц одинаковой размерности
void MultiSquareMatrix(SquareMatrix mat1, SquareMatrix mat2, SquareMatrix multimatrix, int size) { 
	for (unsigned int i = 0; i < size;++i) {//строки
		double sum = 0;
		for (unsigned int j = 0; j < size; ++j) {
			for (unsigned int m = 0; m < size; ++m) {//строки
				sum = sum + mat1[i][j] * mat2[m][j];
			}
			multimatrix[i][j] = round(sum * Rounding_Const)/Rounding_Const;
			sum = 0;
		}
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args) {//Проверка аргументов
		return 1;
	}
	ifstream inputMatrix1, inputMatrix2;
	inputMatrix1.open(args->matrix1);
	if (!inputMatrix1.is_open()) {
		cout << "Failed to open " << args->matrix1 << " for reading" << endl;
		return 1;
	}
	inputMatrix2.open(args->matrix2);
	if (!inputMatrix2.is_open()) {
		cout << "Failed to open " << args->matrix2 << " for reading" << endl;
		return 1;
	}

	SquareMatrix mat1, mat2;
	ReadMatrix(&inputMatrix1, mat1, Size);
	ReadMatrix(&inputMatrix2, mat2, Size);
	//PrintSquareMatrix(mat1, Size);
	//PrintSquareMatrix(mat2, Size);

	if (inputMatrix1.bad()) {
		cout << Reading_Error << args->matrix1 << endl;
		return 1;
	}
	if (inputMatrix2.bad()) {
		cout << Reading_Error << args->matrix2 << endl;
		return 1;
	}

	SquareMatrix multimatrix;
	MultiSquareMatrix(mat1, mat2, multimatrix, Size);

	PrintSquareMatrix(multimatrix, Size);
	return 0;
}

