#pragma once
#include<iostream>
using namespace std;

class Precede
{
public:
	Precede();
	~Precede();
	int ConvertToIndex(string opr);
	char PrecedeSign(string opr1, string opr2);
private:
	string OprRelation[7];
};

