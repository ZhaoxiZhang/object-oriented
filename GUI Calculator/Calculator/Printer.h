#pragma once
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<fstream>
using namespace std;

class Printer
{
private:
	ofstream fout;
public:
	Printer();
	~Printer();
	void FileOpen(string FileName);
	void FileClose();
	void OutPutExpr(string str);
	void OutPut(queue<string>q);
	void PutAns(stack<double>stk);
	void OutputToFile(queue<string>q);
	void PutAnsTofile(stack<double>stk);
};

