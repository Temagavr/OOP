#include <iostream>
#include <string>
using namespace std;

const int Lenght_Byte = 8;
const int Number_System = 10;
const string Invalid_Arg = "Invalid first argument";
const string Invalid_Args_Count = "Invalid agruments count";
const string Usage_Program = "Usage Flipbyte.exe <number>(0-255)";

unsigned char Flipbyte(unsigned char* basebyte) {
	unsigned char flipbyte = 0;
	for (int j = 0; j != Lenght_Byte;++j, *basebyte >>= 1) {
		unsigned char temp = *basebyte;
		temp = temp << Lenght_Byte - 1;
		temp = temp >> j;
		flipbyte = flipbyte | temp;
	}
	return flipbyte;
}

bool CheckArgs(int argc, char* argv[]) {
	if (argc != 2) {
		cout << Invalid_Args_Count << endl;;
		cout << Usage_Program << endl;
		return false;
	}
	return true;
}

bool ConvertArg(const char *strNum, unsigned char *byte) {
	if (!isdigit(*strNum)) {
		return false;
	}
	char* End = NULL;
	int tempNum = strtol(strNum, &End, Number_System);
	if (tempNum == 0 && (strNum == '\0' || *End != '\0')) {
		return false;
	}
	if (tempNum >= 0 && tempNum <= 255) {
		*byte = (unsigned char)tempNum;
		return true;
	}
	else {
		return false;
	}
}

int main(int argc, char* argv[])
{
	if (!CheckArgs(argc, argv)) {
		return 1;
	};
	unsigned char normalByte;
	if (!ConvertArg(argv[1], &normalByte)) {
		cout << Invalid_Arg << endl;
		return 1;
	}
	unsigned char flipedbyte = Flipbyte(&normalByte);

	cout << (int)flipedbyte << endl;
	return 0;
}
