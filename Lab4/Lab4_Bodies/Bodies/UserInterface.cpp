#include "UserInterface.h"

shared_ptr<CBody> UserInterface::FindMaxMass(vector<shared_ptr<CBody>>& bodies)
{
	double maxMass = 0;
	int pointer = 0;
	for (int i = 0; i < bodies.size();++i) {
		CBody* temp = bodies[i].get();
		double tempMass = temp->GetMass();
		if (maxMass < tempMass) {
			pointer = i;
			maxMass = tempMass;
		}
	}
	shared_ptr<CBody> maxMassBody = bodies[pointer];
	return maxMassBody;
}

shared_ptr<CBody> UserInterface::FindMinMassInWater(vector<shared_ptr<CBody>>& bodies)
{

	double minMass = 99999999.9;
	int pointer = 0;
	for (int i = 0; i < bodies.size();++i) {
		CBody* temp = bodies[i].get();
		double tempMass = (temp->GetDensity() - 1000) * 10 * temp->GetVolume();
		if (minMass > tempMass) {
			pointer = i;
			minMass = tempMass;
		}
	}
	shared_ptr<CBody> minMassBody = bodies[pointer];
	return minMassBody;
}

void UserInterface::UserMenu(vector<shared_ptr<CBody>>& bodies, istream& input, ostream& output)
{
	int menuNum;
	while (true) {
		output << "�������� ����:" << endl;
		output << "1 - �����" << endl;
		output << "2 - �����" << endl;
		output << "3 - �������" << endl;
		output << "4 - ��������������" << endl;
		output << "0 - �����" << endl;
		input >> menuNum;
		if (menuNum == 0) {
			break;
		}
		else {
			double density;
			output << "������� ���������: ";
			input >> density;
			if (menuNum == 1) {
				double rad;
				output << "������� ������(�): ";
				input >> rad;
				bodies.push_back(make_shared<CSphere>(rad, density));
			}
			if (menuNum == 2) {
				double baseRad, height;
				output << "������� ������ ���������(�): ";
				input >> baseRad;
				output << "������� ������(�): ";
				input >> height;
				bodies.push_back(make_shared<CCone>(baseRad, height, density));
			}
			if (menuNum == 3) {
				double baseRad, height;
				output << "������� ������ ���������(�): ";
				input >> baseRad;
				output << "������� ������(�): ";
				input >> height;
				bodies.push_back(make_shared<CCylinder>(baseRad, height, density));
			}
			if (menuNum == 4) {
				double width, height, depth;
				output << "������� ������(�): ";
				input >> height;
				output << "������� ������(�): ";
				input >> width;
				output << "������� �����(�): ";
				input >> depth;
				bodies.push_back(make_shared<CParallelepiped>(width, depth, height, density));
			}
		}
	}

}

void UserInterface::PrintBody(shared_ptr<CBody> body, ostream& output)
{
	CBody* temp = body.get();
	temp->PrintInfo(output);
	output << endl;
}

void UserInterface::PrintAllBodies(vector<shared_ptr<CBody>>& bodies, ostream& output)
{
	for (int i = 0; i < bodies.size();++i) {
		PrintBody(bodies[i], output);
	}
}
