#pragma once
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<fstream>
using namespace std;

class Print
{
public:
	Print();
	~Print();
	ofstream fout;
	void OutPutExpr(string str);
	void OutPut(queue<string>q);
	void PutAns(stack<double>stk);
	void OutputToFile(queue<string>q);
	void PutAnsTofile(stack<double>stk);
};

