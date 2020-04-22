#include <iostream>
#include "CTVSet.h"

using namespace std;
int main()
{
	int menu = 0;
	CTVSet* TV = new CTVSet();
	while (true) {
		cout << endl;
		cout << "Turn TV on - 1" << endl;
		cout << "Turn TV off - 2" << endl;
		cout << "Select channel - 3" << endl;
		cout << "Info about TV - 4" << endl;
		cout << "Exit - 0" << endl;
		cin >> menu;
		if (menu == 1) {
			TV->TurnOn();
		}
		if (menu == 2) {
			TV->TurnOff();
		}
		if (menu == 3) {
			int channel = 1;
			cout << "Enter channel (1-99): ";
			cin >> channel;
			TV->SelectChannel(channel);
		
		}
		if (menu == 4) {
			TV->Info(cout);
		}
		if (menu == 0) {
			break;
		}
	}
	return 0;
}
