#pragma once
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include "calculation.h"
#include "numconvert.h"
#include "operate.h"
#include "precede.h"
using namespace std;

class Calculation
{
public:
	Calculation();
	~Calculation();
	stack<double>NumCalculator(queue<string>que);
private:
	NumConvert transform;
	Operate cal;
	Precede priority;
};

