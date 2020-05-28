#include <iostream>
#include <memory>
#include <vector>
#include "CBody.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CParallelepiped.h"
#include "CSphere.h"
#include "UserInterface.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	//vector<unique_ptr<CBody>> bodies;
	vector<shared_ptr<CBody>> bodies;
	UserInterface UI = UserInterface();
	UI.UserMenu(bodies, cin, cout);
	UI.PrintAllBodies(bodies, cout);
	if (bodies.size() != 0) {
		//shared_ptr<CBody> maxMassBody = FindMaxMass(bodies);
		cout << "Тело с наибольшей массой: " << endl;
		UI.PrintBody(UI.FindMaxMass(bodies), cout);
		//shared_ptr<CBody> minMassBodyInWater = FindMinMassInWater(bodies);
		cout << "Самое легкое тело в воде: " << endl;
		UI.PrintBody(UI.FindMinMassInWater(bodies), cout);
	}
	return 0;
}
