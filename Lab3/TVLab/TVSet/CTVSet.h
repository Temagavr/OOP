#pragma once
#include<iostream>
using namespace std;

class CTVSet
{
public:
	CTVSet();
	~CTVSet();
	bool TurnOn();
	bool TurnOff();
	bool SelectChannel(int channel);
	void Info(ostream& output);
	int GetChannel();
private:
	bool power;
	int channel;
	int lastChannel;
};
