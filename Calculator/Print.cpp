#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include "print.h"
using namespace std;


void Print::output(queue<string>q)
{
	while (!q.empty())
	{
		cout << q.front();
		q.pop();
	}
}

void Print::putans(stack<double>stk)
{
	cout << stk.top() << endl;
}

