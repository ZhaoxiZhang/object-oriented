#include<iostream>
#include<string>
#include<queue>
#include "calculator.h"
using namespace std;


queue<string>Scan::ToStringQueue(string  input)
{
	int len = input.size();
	queue<string>que;
	
	
	for (int i=0;i<len;)
	{
		string tmp = "";
		
		while (i < len && input[i] <= '9'  && input[i] >= '0')
		{
			tmp += input[i++];
		}
		
		if(tmp.size() > 10)
		{
			cerr << "ERROR!";
			
			while (!que.empty())
			{
				que.pop();
			}
			
			break;
		}
		
		if (!tmp.empty())
		{
			que.push(tmp); 
		}
		
		while (i < len && 
		             (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'
					                                     || input[i] == '(' ||input[i] == ')'))
		{
			tmp = input[i++];
			que.push(tmp);
		}
	}
	return que;
}


void Print::output(queue<string>q)
{
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
}


istream &read(istream &is, Scan &expr)
{
	is >> expr.in;
	return is;
}
