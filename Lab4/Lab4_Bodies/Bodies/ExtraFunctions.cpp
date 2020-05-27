#include "ExtraFunctions.h"

shared_ptr<CBody> FindMaxMass(vector<shared_ptr<CBody>>& bodies)
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

shared_ptr<CBody> FindMinMassInWater(vector<shared_ptr<CBody>>& bodies)
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
