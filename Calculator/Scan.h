#ifndef SCAN_H_
#define SCAN_H_ 
#include<string>
#include<queue>
using namespace std;


class Scan
{
	friend istream &read(istream &, Scan &);
	public:
		string in;
		queue<string>ToStringQueue(string  input);
};


istream &read(istream &, Scan &);


#endif
