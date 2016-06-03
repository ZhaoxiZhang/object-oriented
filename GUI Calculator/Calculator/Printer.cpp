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
	cout << stk.top() << endl;
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
	fout << stk.top() << endl;
}

