#include "CTVSet.h"
using namespace std;

CTVSet::CTVSet() {
	CTVSet::power = false;
	CTVSet::channel = 0;
	CTVSet::lastChannel = 0;
}

bool CTVSet::TurnOn()
{
	if (CTVSet::power == false && CTVSet::channel == 0 && CTVSet::lastChannel == 0) {
		CTVSet::power = true;
		CTVSet::channel = 1;
		return true;
	}
	else if (CTVSet::power == false) {
		CTVSet::power = true;
		CTVSet::channel = CTVSet::lastChannel;
		return true;
	}
	else {
		cout << endl << "TV already turned on" << endl;
		return false;
	}
}

bool CTVSet::TurnOff()
{
	if (CTVSet::power == true) {
		CTVSet::power = false;
		CTVSet::lastChannel = CTVSet::channel;
		CTVSet::channel = 0;
		return true;
	}
	else
	{
		cout << endl << "TV already turned off" << endl;
		return false;
	}
}

bool CTVSet::SelectChannel(int channel)
{
	if (channel > 0 && channel < 100) {
		CTVSet::channel = channel;
		return true;
	}
	else {
		cout << endl << "Channel out of range" << endl;
		return false;
	}
}

void CTVSet::Info(ostream& output) {
	if (CTVSet::power == false) {
		output << endl << "TV is turned off" << endl;
	}
	else {
		output << endl << "TV is turned on" << endl;
	}
	output << "TV on channel " << CTVSet::channel << endl;

}

int CTVSet::GetChannel()
{
	return CTVSet::channel;
}
