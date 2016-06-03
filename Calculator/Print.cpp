#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<fstream>
#include "print.h"
using namespace std;


void Print::OutPut(queue<string>q)
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

void Print::OutPutExpr(string str)
{
	cout << str << " ";
}

void Print::PutAns(stack<double>stk)
{
    cout << stk.top() << endl;
}

void Print::OutputToFile(queue<string>q)
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

void Print::PutAnsTofile(stack<double>stk)
{
    fout << stk.top() << endl;
}

