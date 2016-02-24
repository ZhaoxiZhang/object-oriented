#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include<string>
#include<queue>
using namespace std;


class Scan
{
	private:
		//string in;
	friend istream &read(istream &, Scan &);
	public:
		string in;
		queue<string>ToStringQueue(string  input);
};


class Print
{
	public:
		void output(queue<string>q);
}; 


istream &read(istream &, Scan &);


#endif
