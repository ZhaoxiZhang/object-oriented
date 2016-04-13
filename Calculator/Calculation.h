#ifndef CALCULATION_H_
#define CALCULATION_H_
#include<iostream> 
#include<string>
#include<queue>
#include<stack>
#include "numconvert.h"
#include "operate.h"
#include "precede.h" 
using namespace std;

class Calculation
{
	private:
		NumConvert transform;
		Operate cal;
		Precede priority;
	public:
		stack<double>NumCalculator(queue<string>que);
};

#endif

