#pragma once
#include <memory>
#include <vector>
#include "CBody.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CParallelepiped.h"
#include "CSphere.h"
using namespace std;

shared_ptr<CBody> FindMaxMass(vector<shared_ptr<CBody>>& bodies);
shared_ptr<CBody> FindMinMassInWater(vector<shared_ptr<CBody>>& bodies);
