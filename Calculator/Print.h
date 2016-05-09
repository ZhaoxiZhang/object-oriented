#ifndef PRINT_H_
#define PRINT_H_
#include<string>
#include<queue>
#include<stack>
#include<fstream>
using namespace std;


class Print
{
	public:
		ifstream fin;
		ofstream fout;
		void outputexpr(string str);
		void output(queue<string>q);
		void putans(stack<double>stk);
		void OutputToFile(queue<string>q);
		void PutAnsTofile(stack<double>stk);
}; 


#endif
