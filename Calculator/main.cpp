#include<iostream>
#include<string>
#include<queue>
#include"calculator.h"

int main()
{
	Scan ipt;
	Print opt;
	queue<string>que;
	read(cin,ipt);
	que = ipt.ToStringQueue(ipt.in);
	opt.output(que);
	return 0;
} 
