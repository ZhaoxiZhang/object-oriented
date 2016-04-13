#ifndef PRECEDE_H_
#define PRECEDE_H_
#include<iostream>
using namespace std;

class Precede
{
	private:
		string OprRelation[7];
	public:
		Precede();
		int ConvertToIndex(string opr);
		char PrecedeSign(string opr1,string opr2);
		
};

#endif
