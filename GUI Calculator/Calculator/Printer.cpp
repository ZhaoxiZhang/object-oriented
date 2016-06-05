#include "stdafx.h"
#include "Printer.h"


Printer::Printer()
{
}


Printer::~Printer()
{
}

void Printer::FileOpen(string FileName)
{
	fout.open(FileName);
}

void Printer::FileClose()
{
	fout.close();
}

void Printer::OutPut(queue<string>q)
{
	if (q.empty())
	{
		cerr << "´íÎó£¡" << endl;
	}
	else
	{
		while (!q.empty())
		{
			cout << q.front();
			q.pop();
		}
	}
}

void Printer::OutPutExpr(string str)
{
	cout << str << " ";
}

void Printer::PutAns(stack<double>stk)
{
	cout.precision(10);
	double tmp = stk.top();
	if (tmp == -0)
	{
		cout << "0" << endl;
	}
	else
	{
		cout << stk.top() << endl;
	}
}

void Printer::OutputToFile(queue<string>q)
{
	if (q.empty())
	{
		fout << "´íÎó£¡" << endl;
	}
	else
	{
		while (!q.empty())
		{
			fout << q.front();
			q.pop();
		}
	}
}

void Printer::PutAnsTofile(stack<double>stk)
{
	fout.precision(10);
	double tmp = stk.top();
	if (tmp == -0)
	{
		fout << "0" << endl;
	}
	else
	{
		fout << stk.top() << endl;
	}
}

