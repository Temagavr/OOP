#include "CBody.h"

CBody::CBody(string type, double density) {
	CBody::density = density;
	CBody::type = type;
}

CBody::~CBody()
{
}

double CBody::GetDensity()
{
	return CBody::density;
}

double CBody::GetMass()
{
	return round(GetDensity() * GetVolume() * 1000) / 1000;
}

void CBody::PrintInfo(ostream& output)
{
	output << "���: " << type << endl;
	output << "�����: " << GetMass() << endl;
	output << "�����: " << GetVolume() << endl;
	output << "���������: " << GetDensity() << endl;
	OtherParameters(output);
}

