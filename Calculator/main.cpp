#include<iostream>
#include<string>
#include<queue>
#include "calculation.h"
#include "numconvert.h"
#include "precede.h"
#include "operate.h"
#include "print.h"
#include "scan.h"

int main(int argc,char* argv[])
{
	int flag = 1;
	queue<string>que;
	stack<double>stk;
	string input;

	Calculation cal;
	Print opt;
	Scan  ipt;

	read(cin,ipt);

	if (ipt.in == "-a")
	{
		read(cin,ipt);
		flag = 0;
	}

	que = ipt.ToStringQueue(ipt.in);

	if (que.empty())
	{
		cerr << "´íÎó£¡" << endl; 
	}
	else
	{
		stk = cal.NumCalculator(que);

		if (!flag)
		{
			opt.output(que);
			cout << "=";
		}

		opt.putans(stk);
	}
	
	return 0;
}
