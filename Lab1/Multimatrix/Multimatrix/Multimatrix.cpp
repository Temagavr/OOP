#include <iostream>
#include <fstream>
#include <optional>
#include <string>

using namespace std;

typedef int SquareMatrix [3][3];

struct Args {
	string matrix1;
	string matrix2;
};

optional<Args> ParseArgs(int argc, char* argv[]) {
	if (argc != 3) {
		return nullopt;
	}
	Args args;
	args.matrix1 = argv[1];
	args.matrix2 = argv[2];
	return args;
}

void printSquareMatrix(SquareMatrix mat, int size) {//Печать матрицы
	for (unsigned int i = 0; i < size;++i) {
		for (unsigned int j = 0; j < size;++j) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void readMatrix(ifstream *file, SquareMatrix mat, int size){//Чтение матрицы
	for (unsigned int i = 0; i < size;++i) {
		for (unsigned int j = 0; j < size;++j) {
			int num;
			*file >> num;
			mat[i][j] = num;
		}
	}
}

void multiSquareMatrix(SquareMatrix mat1, SquareMatrix mat2, SquareMatrix multimatrix, int size) {//Умножение квадратных матриц 
	for (unsigned int i = 0; i < size;++i) {//строки
		int sum = 0;
		for (unsigned int j = 0; j < size; ++j) {
			for (unsigned int m = 0; m < size; ++m) {//строки
				sum = sum + mat1[i][j] * mat2[m][j];
			}
			multimatrix[i][j] = sum;
			sum = 0;
		}
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args) {//Проверка аргументов
		cout << "Invalid agruments count\n";
		cout << "Usage Multimatrix.exe <matrix1.txt> <matrix2.txt>\n";
		return 1;
	}
	ifstream inputMatrix1, inputMatrix2;
	inputMatrix1.open(args->matrix1);
	if (!inputMatrix1.is_open()) {
		cout << "Failed to open " << args->matrix1 << " for reading\n";
	}
	inputMatrix2.open(args->matrix2);
	if (!inputMatrix2.is_open()) {
		cout << "Failed to open " << args->matrix2 << " for reading\n";
	}

	const int size = 3;
	SquareMatrix mat1, mat2;
	readMatrix(&inputMatrix1, mat1, size);
	readMatrix(&inputMatrix2, mat2, size);
	printSquareMatrix(mat1, size);
	printSquareMatrix(mat2, size);

	SquareMatrix multimatrix;
	multiSquareMatrix(mat1, mat2, multimatrix, size);
	
	printSquareMatrix(multimatrix, size);
	
	return 0;
}

