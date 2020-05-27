
#include <iostream>
#include <memory>
#include <vector>
#include "CBody.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CParallelepiped.h"
#include "CSphere.h"
#include "ExtraFunctions.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	//vector<unique_ptr<CBody>> bodies;
	vector<shared_ptr<CBody>> bodies;
	int menuNum;
	while (true) {
		cout << "Выберете тело:" << endl;
		cout << "1 - Сфера" << endl;
		cout << "2 - Конус" << endl;
		cout << "3 - Цилиндр" << endl;
		cout << "4 - Параллелепипед" << endl;
		cout << "0 - Выход" << endl;
		cin >> menuNum;
		if (menuNum == 0) {
			break;
		}
		else {
			double density;
			cout << "Введите плотность: ";
			cin >> density;
			if (menuNum == 1) {
				double rad;
				cout << "Введите радиус(м): ";
				cin >> rad;
				bodies.push_back(make_shared<CSphere>(rad, density));
			}
			if (menuNum == 2) {
				double baseRad, height;
				cout << "Введите радиус основания(м): ";
				cin >> baseRad;
				cout << "Введите высоту(м): ";
				cin >> height;
				bodies.push_back(make_shared<CCone>(baseRad, height, density));
			}
			if (menuNum == 3) {
				double baseRad, height;
				cout << "Введите радиус основания(м): ";
				cin >> baseRad;
				cout << "Введите высоту(м): ";
				cin >> height;
				bodies.push_back(make_shared<CCylinder>(baseRad, height, density));
			}
			if (menuNum == 4) {
				double width, height, depth;
				cout << "Введите высоту(м): ";
				cin >> height;
				cout << "Введите ширину(м): ";
				cin >> width;
				cout << "Введите длину(м): ";
				cin >> depth;
				bodies.push_back(make_shared<CParallelepiped>(width, depth, height, density));
			}
		}
	}

	for (int i = 0; i < bodies.size();++i) {
		CBody* temp = bodies[i].get();
		temp->PrintInfo(cout);
		cout << endl;
	}
	if (bodies.size() != 0) {
		shared_ptr<CBody> maxMassBody = FindMaxMass(bodies);
		cout << "Тело с наибольшей массой: " << endl;
		CBody* temp = maxMassBody.get();
		temp->PrintInfo(cout);
		cout << endl;
		shared_ptr<CBody> minMassBodyInWater = FindMinMassInWater(bodies);
		cout << "Самое легкое тело в воде: " << endl;
		CBody* temp1 = minMassBodyInWater.get();
		temp1->PrintInfo(cout);
		cout << endl;
	}
	return 0;
}
