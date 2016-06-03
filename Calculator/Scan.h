#ifndef SCAN_H_
#define SCAN_H_ 
#include<string>
#include<queue>
#include<fstream>
using namespace std;


class Scan
{
	private:
		
	public:
		ifstream fin;
		string in;
		friend istream &read(istream &, Scan &);
		queue<string>ToStringQueue(string  input);
};


istream &read(istream &, Scan &);


#endif
